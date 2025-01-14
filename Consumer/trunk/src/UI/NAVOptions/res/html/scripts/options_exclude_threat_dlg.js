////////////////////////
//
// PROPRIETARY / CONFIDENTIAL.
// Use of this product is subject to license terms.
// Copyright � 2006 Symantec Corporation.
// All rights reserved.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

// options_exclude_threat_dlg.js

g_ModuleID = 3023; // From ccModuleID.h
g_ScriptID = 127;  // This uniquely defines this script file to the error handler

var OldItem = '';

// Disable Drag-and-drop support
document.ondragstart = function(){return false;}

// Enable/Disable OK button
function EnableOK()
{
  try
  {
      with(document.options_exclude_threat_dlg)
      {
        // A valid entry must at least one charecter
        if (document.all.Item.value.length)
        {
			ButtonEnable(OK);
        }
        else
        {
			ButtonDisable(OK);
        }
      }
  }
  catch(err)
  {
    g_ErrorHandler.DisplayException (err);
  }

  return true;
}

// Browse disk for excluded files
function BrowseExclusions()
{
	try
	{
		with(document.options_exclude_threat_dlg)
		{
			Item.value = window.external.Global.NAVOptions.Browse(3, Item.value);
			EnableOK();
		}
	}
	catch(err)
	{
		window.external.Global.NAVOptions.NAVError.LogAndDisplay(window.external.Global.g_HWND);
	}

  return false;
}

// Launch Threat Exclusions help
function Help()
{
    try
    {
       window.external.Global.NAVOptions.Help(11715); // IDH_NAVW_OPTIONS_THREAT_CAT_EXCLUSIONS_NEWEDIT 11715
    }
    catch(err)
    {
       window.external.Global.NAVOptions.NAVError.LogAndDisplay(window.external.Global.g_HWND);
    }
}

// save options values from the screen
function Save()
{
  try
  {
	  with(document.options_exclude_threat_dlg)
	  {
		// Match only a valid path
			
	    // Remove leading and trailing white space
        Item.value = trim(Item.value);
        var result = 0;
        if( Item.value.length != 0 )
            result = window.external.Global.NAVOptions.ValidateExclusionPath(Item.value);
        // Check for an empty exclusion item or an invalid one
		if (Item.value.length == 0 || !result)
		{
		  try
		  {
			var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
		  }
		  catch (NAVErr)
		  {
			g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,
							document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
			location.href = 'closeme.xyz';
			return;
		  }
		  sww.MsgBox(document.all.IlegalFile.innerText + ' (' + Item.value + ')', document.title, 48);
		  delete sww;
		  Item.value = OldItem;
		  EnableOK();
		  return;
		}
        // Now check for a path with wildcard characters in it which are
        // no longer supported
        if( 2 == result )
        {
            try
		  {
			var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
		  }
		  catch (NAVErr)
		  {
			g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,
							document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
			location.href = 'closeme.xyz';
			return;
		  }
		  sww.MsgBox(document.all.WildCardInPath.innerText, document.title, 48);
		  delete sww;
		  Item.value = OldItem;
		  EnableOK();
		  return;
        }

        // Also deny the *.* extension exclusion
        if( 3 == result )
        {
            try
		    {
			    var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
		    }
		    catch (NAVErr)
		    {
			    g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,
							    document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
			    location.href = 'closeme.xyz';
			    return;
		    }
		    sww.MsgBox(document.all.AllPathsError.innerText, document.title, 48);
		    delete sww;
		    Item.value = OldItem;
		    EnableOK();
		    return;
        }

		// Set the NAVOptions theat exclusion item from the HTML controls
		with(window.external.Global.frames[2].document.all)
		{
		  try
		  {
            var varResult;

			try
			{
				// Attempt to save this Exclusion item
				varResult = window.external.Global.NAVOptions.SetPathExclusionItem(
					window.external.Global.AddSelectedIndex, // Index attempting to set 
					Item.value.toLowerCase(), 			// Path of exclusion
					Math.abs(IncludeSubfolders.checked) 	// Include subfolders?
				);
			}
			catch(err)
			{
				window.external.Global.NAVOptions.NAVError.LogAndDisplay(window.external.Global.g_HWND);
				location.href = 'closeme.xyz';
				return;
			}
            if( !varResult ) // Failed to commit the Exclusion item
            {
                try
			    {
				    var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
			    }
			    catch (NAVErr)
			    {
				    g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,  
								    document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
				    location.href = 'closeme.xyz';
					return;
			    }
			    sww.MsgBox(document.all.ExclusionError.innerText + ' (' + Item.value + ')', document.title, 48);
			    delete sww;
			    return;
            }
            else if( varResult == 3) // Duplicate item
            {
                try
			    {
				    var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
			    }
			    catch (NAVErr)
			    {
				    g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,  
					        	    document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
				    location.href = 'closeme.xyz';
					return;
			    }
			    sww.MsgBox(document.all.DuplicateExclusion.innerText + ' (' + Item.value + ')', document.title, 48);
			    delete sww;
			    return;
            }
            else if( varResult == 4 ) // Too many exclusions
            {
                try
			    {
				    var sww = new ActiveXObject('CcWebWnd.ccWebWindow');
			    }
			    catch (NAVErr)
			    {
				    g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,  
					        	    document.frames("Errors").ERROR_CREATING_NAVWEBWINDOW_OBJECT_ID.innerText);
				    location.href = 'closeme.xyz';
					return;
			    }
			    sww.MsgBox(document.all.TooManyExclusions.innerText, document.title, 48);
			    delete sww;
			    return;            
            }
            // If adding the exclusion update the length
            if( window.external.Global.AddExclusion )
            {
                ++FS_Exclusions.options.length;
            
                // Add the new exlusion to the UI
			    FS_Exclusions.options[window.external.Global.AddSelectedIndex-1].text = Item.value;
            }
            else
			{
                // Update the existing exclusion
                FS_Exclusions.options[window.external.Global.AddSelectedIndex].text = Item.value;
			}
		  }
		  catch (NAVErr)
		  {
			g_ErrorHandler.DisplayNAVError (document.frames("Errors").ERROR_INTERNAL_ERROR_REINSTALL.innerText,
							document.frames("Errors").ERROR_CREATING_EXCLUSION_OBJECT_ID.innerText);
			location.href = 'closeme.xyz';
			return;
		  }
		}  // with(window.external.Global.frames[1].document.all)
	  
	  window.returnValue = Item.value;
	  location.href = 'closeme.xyz';
	  
	} // with(document.options_exclude_threat_dlg)
  }
  catch (err)
  {
	g_ErrorHandler.DisplayException (err);
	location.href = 'closeme.xyz';
	return;
  }
}

// Initialize the from with the options value
function initialize_options_exclude_threat_dlg()
{
  try
  {
	  with(document.options_exclude_threat_dlg)
	  {
		// Set caption
		document.title = window.external.Global.NAVOptions.ProductName;
			
	    // Enable scrolling for high-contrast mode
	    // Fix from defect 1-4AROGV. Need to shrink input in high contrast mode.
	    if( window.external.Global.NAVOptions.IsHighContrastMode )
	    {
	        body_ed.scroll = "auto";
	        Item.size = Item.size - 4;
	        document.options_exclude_threat_dlg.OK.style.border = '1px solid white';
	        document.options_exclude_threat_dlg.Cancel.style.border = '1px solid white';
        }
	        
		with(window.external.Global.frames[2].document.all)
		{   
		  // Set these HTML controls from the NAVOptions.EXCLUSIONS collection
		  if (!window.external.Global.AddExclusion && FS_Exclusions.selectedIndex >= 0)
		  {
		    // Set the text for this item
			OldItem = Item.value = FS_Exclusions.options[FS_Exclusions.selectedIndex].text;
			
			// Set the subfolder checked for this item
			var bSubFolder = true;
			try
            {
                bSubFolder = window.external.Global.NAVOptions.PathExclusionItemSubFolder(FS_Exclusions.selectedIndex);
            }
            catch(err)
            {
                window.external.Global.NAVOptions.NAVError.LogAndDisplay(window.external.Global.g_HWND);
            }

			IncludeSubfolders.checked = bSubFolder;
		  }
		  else // This is a new item, set subfolders as the default
		  {
		    IncludeSubfolders.checked = true;
		  }

		  // Set focus to first element
		  Item.focus();

		  EnableOK();
		}
	  }
  }
  catch (err)
  {
	g_ErrorHandler.DisplayException (err);
	location.href = 'closeme.xyz';
	return;
  }
}
