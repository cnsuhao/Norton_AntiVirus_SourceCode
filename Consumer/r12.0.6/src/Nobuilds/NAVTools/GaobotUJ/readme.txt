W32.Gaobot.UJ Removal Tool

Discovered on: April 1, 2004 
Last Updated on: April 12, 2004 10:22:21 AM PDT 

--------------------------------------------------------------------------------  
Symantec Security Response has developed a removal tool to clean the infections 
of W32.Gaobot.UJ.

WHAT THE TOOL DOES

The W32.Gaobot.UJ Removal Tool does the following: 

1.  Terminates the W32.Gaobot.UJ viral processes and services. 
2.  Deletes the W32.Gaobot.UJ files. 
3.  Deletes the dropped files. 
4.  Deletes the registry values that the worm added.

WHAT THE TOOL DOES NOT DO

This tool does not restore the hosts file if it has been modified. Please see 
Step 6 of the Removal Instructions for W32.Gaobot.UJ to correct this 
modification. 

--------------------------------------------------------------------------------
COMMAND-LINE SWITCHES AVAILABLE WITH THIS TOOL

Switch             Description 
/HELP, /H, /?      Displays the help message. 

/NOFIXREG          Disables the registry repair. (We do not recommend using this
                   switch.) 

/SILENT, /S        Enables the silent mode. 

/LOG=<path name>   Creates a log file where <path name> is the location in which
                   to store the tool's output. By default, this switch creates 
                   the log file, FxGaoUJ.log, within the same folder from which
                   the removal tool was executed. 

/MAPPED            Scans the mapped network drives. (We do not recommend using 
                   this switch. Refer to the Notes below.) 

/START             Forces the tool to immediately start scanning. 

/EXCLUDE=<path>    Excludes the specified <path> from scanning. (We do not 
                   recommend using this switch.) 
 
/NOFILESCAN        Prevents the scanning of the file system. 


--------------------------------------------------------------------------------
Note: Using the /MAPPED switch does not ensure the complete removal of the virus
on the remote computer, because: 

o  Scanning the mapped drives scans the mapped folders only. This action may not
   include all the folders on the remote computer, leading to missed detections.
o  If a viral file is detected on the mapped drive, the removal will fail if a 
   program on the remote computer uses this file. 

   For these reasons, run the tool on every computer.
--------------------------------------------------------------------------------

OBTAINING AND RUNNING THE TOOL

--------------------------------------------------------------------------------
Note: You need administrative rights to run this tool on Windows NT 4.0, 
Windows 2000, or Windows XP.
--------------------------------------------------------------------------------

1.  Download the FxGaoUJ.exe file from:

    http://securityresponse.symantec.com/avcenter/FxGaobotUJ.exe


2.  Save the file to a convenient location, such as your downloads folder or the
    Windows Desktop (or removable media known to be uninfected, if possible).
 
3.  To check the authenticity of the digital signature, refer to the section, 
    "Digital signature." 

4.  Close all the running programs before running the tool. 

5.  If you are on a network or you have a full-time connection to the Internet, 
    disconnect the computer from the network and the Internet. 

6.  If you are running Windows Me or XP, then disable System Restore. Refer to 
    the section, "System Restore option in Windows Me/XP," for additional 
    details.

--------------------------------------------------------------------------------
CAUTION: If you are running Windows Me/XP, we strongly recommend that you do not
skip this step. The removal procedure may be unsuccessful if Windows Me/XP 
System Restore is not disabled, because Windows prevents outside programs from 
modifying System Restore. 
--------------------------------------------------------------------------------

7.  Shut down the computer and turn off the power. Wait for at least 30 seconds, 
    and then restart the computer in Safe mode or VGA mode. 
    o  For Windows 98, Me, 2000, or XP users, restart the computer in Safe 
       mode. For instructions, read the document, "How to start the computer in 
       Safe Mode." 

8.  Double-click the FxGaoUJ.exe file to start the removal tool. 

9.  Click Start to begin the process, and then allow the tool to run. 

10. Restart the computer. 

11. If you are running Windows Me/XP, then re-enable System Restore. 

12. Run LiveUpdate to make sure that you are using the most current virus 
    definitions.

When the tool has finished running, you will see a message indicating whether 
W32.Gaobot.UJ infected the computer. In the case of a worm removal, the program 
displays the following results: 

o Total number of the scanned files 
o Number of deleted files 
o Number of terminated viral processes 
o Number of fixed registry entries 
o Stopped and deleted viral processes and services

--------------------------------------------------------------------------------
DIGITAL SIGNATURE
FxGaoUJ.exe is digitally signed. Symantec recommends that you only use copies of
FxGaoUJ.exe that have been directly downloaded from the Symantec Security 
Response Web site. To check the authenticity of the digital signature, follow 
these steps: 

1.  Go to http://www.wmsoftware.com/free.htm. 

2.  Download and save the Chktrust.exe file to the same folder in which you 
    saved FxGaobot.exe (for example, C:\Downloads). 

3.  Depending on your operating system, do one of the following: 
    o  Click Start, point to Programs, and then click MS-DOS Prompt. 
    o  Click Start, point to Programs, click Accessories, and then click Command
       Prompt.

4. Change to the folder where FxGaoUJ.exe and Chktrust.exe are stored, and then 
   type:

   chktrust -i FxGaoUJ.exe

   For example, if you saved the file to the C:\Downloads folder, you would 
   enter the following commands:

   cd\
   cd downloads
   chktrust -i FxGaoUJ.exe

   Press Enter after typing each command. If the digital signature is valid, you
   will see the following, "Do you want to install and run "W32.GaoUJ Removal 
   Tool" signed on 6/25/2004 9:03 AM and distributed by Symantec Corporation?

   NOTES: 
   o The date and time displayed in this dialog box will be adjusted to your 
     time zone. 
   o If you are using Daylight Saving time, the displayed time will be exactly 
     one hour earlier. 
   o If this dialog box does not appear, there are two possible reasons: 
     => The tool is not from Symantec. Unless you are sure that the tool is 
        legitimate and that you downloaded it from the legitimate Symantec Web 
        site, do not run it. 
     => The tool is from Symantec and is legitimate: However, your operating 
        system was previously instructed to always trust content from Symantec. 
        For information on this and on how to view the confirmation dialog again, 
        read the document, "How to restore the Publisher Authenticity 
        confirmation dialog box."


5.  Click Yes to close the dialog box.

6.  Type Exit, and then press Enter. This will close the MS-DOS session.

--------------------------------------------------------------------------------
SYSTEM RESTORE OPTION IN WINDOWS ME/XP
Users of Windows Me and Windows XP should temporarily turn off System Restore. 
Windows Me/XP uses this feature, which is enabled by default, to restore the 
files on your computer in case they become damaged. If a virus, worm, or Trojan
infects a computer, System Restore may back up the virus, worm, or Trojan on the
computer.

Windows prevents outside programs, including antivirus programs, from modifying
System Restore. Therefore, antivirus programs or tools cannot remove threats in 
the System Restore folder. As a result, System Restore has the potential of 
restoring an infected file on your computer, even after you have cleaned the 
infected files from all the other locations.

Also, in some cases, online scanners may detect a threat in the System Restore 
folder even though you scanned your computer with an antivirus program and did 
not find any infected files.

For instructions on how to turn off System Restore, read your Windows 
documentation, or one of the following articles: 
o "How to disable or enable Windows Me System Restore" 
o "How to turn off or turn on Windows XP System Restore"

For additional information and an alternative to disabling Windows Me System 
Restore, read the Microsoft Knowledge Base article, "Antivirus Tools Cannot 
Clean Infected Files in the _Restore Folder (Q263455)."

--------------------------------------------------------------------------------

HOW TO RUN THE TOOL FROM A FLOPPY DISK

1.  Insert the floppy disk, which contains the FxGaoUJ.exe  file, in the floppy 
    disk drive. 

2.  Click Start, and then click Run. 

3.  Type the following:

    a:\FxGaoUJ.exe 

    and then click OK:

   NOTES: 
   o  There are no spaces in the command, a:\FxGaoUJ.exe. 
   o  If you are using Windows Me/XP and System Restore remains enabled, you 
      will see a warning message. You can either run the removal tool with the 
      System Restore option enabled or exit the removal tool.

4. Click Start to begin the process, and then allow the tool to run. 

5. If you are using Windows Me, then re-enable System Restore.

