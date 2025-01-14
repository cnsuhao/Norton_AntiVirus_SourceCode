package Win32::Registry;
#######################################################################
#Perl Module for Registry Extensions
# This module creates an object oriented interface to the Win32
# Registry.
#
# NOTE: This package exports four instantiated keys to
# the main:: name space.  ( The pre-defined keys )
# these keys:
# $main::CLASSES_ROOT
# $main::CURRENT_USER
# $main::LOCAL_MACHINE
# $main::USERS
#
#######################################################################

require Exporter;       #to export the constants to the main:: space
require DynaLoader;     # to dynuhlode the module.
use Win32::WinError; 		# for windows constants.

$VERSION = '0.04';

@ISA= qw( Exporter DynaLoader );
@EXPORT = qw(
	HKEY_CLASSES_ROOT
	HKEY_CURRENT_USER
	HKEY_LOCAL_MACHINE
	HKEY_PERFORMANCE_DATA
	HKEY_CURRENT_CONFIG
	HKEY_DYN_DATA
	HKEY_USERS
	KEY_ALL_ACCESS
	KEY_CREATE_LINK
	KEY_CREATE_SUB_KEY
	KEY_ENUMERATE_SUB_KEYS
	KEY_EXECUTE
	KEY_NOTIFY
	KEY_QUERY_VALUE
	KEY_READ
	KEY_SET_VALUE
	KEY_WRITE
	REG_BINARY
	REG_CREATED_NEW_KEY
	REG_DWORD
	REG_DWORD_BIG_ENDIAN
	REG_DWORD_LITTLE_ENDIAN
	REG_EXPAND_SZ
	REG_FULL_RESOURCE_DESCRIPTOR
	REG_LEGAL_CHANGE_FILTER
	REG_LEGAL_OPTION
	REG_LINK
	REG_MULTI_SZ
	REG_NONE
	REG_NOTIFY_CHANGE_ATTRIBUTES
	REG_NOTIFY_CHANGE_LAST_SET
	REG_NOTIFY_CHANGE_NAME
	REG_NOTIFY_CHANGE_SECURITY
	REG_OPENED_EXISTING_KEY
	REG_OPTION_BACKUP_RESTORE
	REG_OPTION_CREATE_LINK
	REG_OPTION_NON_VOLATILE
	REG_OPTION_RESERVED
	REG_OPTION_VOLATILE
	REG_REFRESH_HIVE
	REG_RESOURCE_LIST
	REG_RESOURCE_REQUIREMENTS_LIST
	REG_SZ
	REG_WHOLE_HIVE_VOLATILE
);

@EXPORT_OK = qw(
    RegCloseKey
    RegConnectRegistry
    RegCreateKey
    RegCreateKeyEx
    RegDeleteKey
    RegDeleteValue
    RegEnumKey
    RegEnumValue
    RegFlushKey
    RegGetKeySecurity
    RegLoadKey
    RegNotifyChangeKeyValue
    RegOpenKey
    RegOpenKeyEx
    RegQueryInfoKey
    RegQueryValue
    RegQueryValueEx
    RegReplaceKey
    RegRestoreKey
    RegSaveKey
    RegSetKeySecurity
    RegSetValue
    RegSetValueEx
    RegUnLoadKey
);
$EXPORT_TAGS{ALL}= \@EXPORT_OK;

bootstrap Win32::Registry;

sub import
{
    my( $pkg )= shift;
    if(  "Win32" eq $_[0]  ) {
	Exporter::export( $pkg, "Win32", @EXPORT_OK );
	shift;
    }
    Win32::Registry->export_to_level( 1+$Exporter::ExportLevel, $pkg, @_ );
}

#######################################################################
# This AUTOLOAD is used to 'autoload' constants from the constant()
# XS function.  If a constant is not found then control is passed
# to the AUTOLOAD in AutoLoader.

sub AUTOLOAD {
    my($constname);
    ($constname = $AUTOLOAD) =~ s/.*:://;
    #reset $! to zero to reset any current errors.
    $!=0;
    my $val = constant($constname, @_ ? $_[0] : 0);
    if ($! != 0) {
	if ($! =~ /Invalid/) {
	    $AutoLoader::AUTOLOAD = $AUTOLOAD;
	    goto &AutoLoader::AUTOLOAD;
	}
	else {
	    ($pack,$file,$line) = caller;
	    die "Your vendor has not defined Win32::Registry macro $constname, used at $file line $line.";
	}
    }
    eval "sub $AUTOLOAD { $val }";
    goto &$AUTOLOAD;
}

#######################################################################
# _new is a private constructor, not intended for public use.
#

sub show_me
{
	$self=shift;
	print $self->{'handle'};
}

sub _new
{
	my $self={};
	if ($_[0]){
		$self->{'handle'} = $_[0];
		bless $self
	}
	else{
		undef($self);
	}
	$self;
}

#define the basic registry objects to be exported.
#these had to be hardwired unfortunately.


$main::HKEY_CLASSES_ROOT	= _new(&HKEY_CLASSES_ROOT);
$main::HKEY_CURRENT_USER	= _new(&HKEY_CURRENT_USER);
$main::HKEY_LOCAL_MACHINE	= _new(&HKEY_LOCAL_MACHINE);
$main::HKEY_USERS		= _new(&HKEY_USERS);
$main::HKEY_PERFORMANCE_DATA	= _new(&HKEY_PERFORMANCE_DATA);
$main::HKEY_CURRENT_CONFIG	= _new(&HKEY_CURRENT_CONFIG);
$main::HKEY_DYN_DATA		= _new(&HKEY_DYN_DATA);





#######################################################################
#Open
# creates a new Registry object from an existing one.
# usage: $RegObj->Open( "SubKey",$SubKeyObj );
#               $SubKeyObj->Open( "SubberKey", *SubberKeyObj );

sub Open
{
	my $self = shift;
	
	if( @_ != 2 ){
		die 'usage: Open( $SubKey, $ObjRef )';
	}
	
	($SubKey) = @_;
	local ($Result,$SubHandle);

	$Result = RegOpenKey($self->{'handle'},$SubKey,$SubHandle);
	$_[1] = _new( $SubHandle );
	
	if (!$_[1] ){
		return 0;
	}

 	if(!$Result){
		$! = Win32::GetLastError();
	}

	# return a boolean value
	return($Result);

}

#######################################################################
#Close
# close an open registry key.
#
sub Close
{
	my $self = shift;
	
	if( @_ != 0 ){
		die "usage: Close()";
	}

	$Result = RegCloseKey( $self->{'handle'});
	undef($self);

	if(!$Result){
		$! = Win32::GetLastError();
	}

	return($Result);
}

#######################################################################
#Connect
# connects to a remote Registry object, returning it in $ObjRef.
# returns false if it fails.
# usage: $RegObj->Connect( $NodeName, $ObjRef );

sub Connect
{
	local ($Node);
	my $self = shift;
	 
	if( @_ != 2 )
	{
		die 'usage: Connect( $NodeName, $ObjRef )';
	}
	 
	($Node) = @_;
	local ($Result,$SubHandle);

	$Result = RegConnectRegistry ($Node, $self->{'handle'}, $SubHandle);
	$_[1] = _new( $SubHandle );

	if (!$_[1] ){
		return 0;
	}

	if(!$Result){
		$! = Win32::GetLastError();
	}

	# return a boolean value
	return($Result);
}  

#######################################################################
#Create
# open a subkey.  If it doesn't exist, create it.
#

sub Create
{
	my $self = shift;

	if( @_ != 2 ){
		die 'usage: Create( $SubKey,$ScalarRef )';
	}

	($SubKey) = @_;
	local ($Result,$SubHandle);

	#call the API, and create the object.
	$Result = RegCreateKey($self->{'handle'},$SubKey,$SubHandle);
	$_[1] = _new ( $SubHandle );
	if (!$_[1]){
		return(0);
	}
	#error checking

 	if(!$Result){
		$! = Win32::GetLastError();
	}

	return($Result);

}

#######################################################################
#SetValue
# SetValue sets a value in the current key.
#

sub SetValue
{
	my $self = shift;
	if( @_ != 3 ){
		die 'usage: SetValue($SubKey,$Type,$value )';
	}

	local($SubKey,$type,$value) = @_;

	# set the value.
	$Result = RegSetValue( $self->{'handle'},$SubKey,$type,$value);
	
 	if(!$Result){
		$! = Win32::GetLastError();
	}

	return($Result);

}

sub SetValueEx
{
	my $self = shift;
	if( @_ != 4 ){
		die 'usage: SetValueEx( $SubKey,$Reserved,$type,$value )';
	}

	local( $SubKey,$Reserved,$type,$value) =@_;

	$Result = RegSetValueEx( $self->{'handle'},$SubKey,$Reserved,$type,$value);
	
	if(!$Result){
		$! = Win32::GetLastError();
	}

	return($Result);
}

#######################################################################
#QueryValue  and QueryKey
# QueryValue gets information on a value in the current key.
# QueryKey "    "       "       "  key  "       "       "       

sub QueryValue
{
	my $self = shift;

	if( @_ != 2 ){
		die 'usage: QueryValue( $SubKey,$valueref )';
	}

	#Query the value.
	$Result = RegQueryValue( $self->{'handle'}, $_[0], $_[1]);

	#check the results.

 	if(!$Result){
		$! = Win32::GetLastError();
	}

	return($Result);
}

sub QueryKey
{
	my $garbage;
	my $self = shift;

	if( @_ != 3 ){
		die 'usage: QueryKey( $classref, $numberofSubkeys, $numberofVals )';
	}

	local ($Result);

	$Result = RegQueryInfoKey( $self->{'handle'}, $_[0],
				   $garbage, $garbage, $_[1],
				   $garbage, $garbage, $_[2],
				   $garbage, $garbage, $garbage, $garbage);


 	if(!$Result){
		$! = Win32::GetLastError();
	}
	return($Result);
}

#######################################################################
#QueryValueEx
# QueryValueEx gets information on a value in the current key.

sub QueryValueEx
{
	my $self = shift;

	if( @_ != 3 ){
		die 'usage: QueryValueEx( $SubKey,$type,$valueref )';
	}

	#Query the value.
	$Result = RegQueryValueEx( $self->{'handle'}, $_[0], NULL, $_[1], $_[2] );

	#check the results.

 	if(!$Result) {
		$! = Win32::GetLastError();
	}

	return($Result);
}

#######################################################################
#GetKeys
#Note: the list object must be passed by reference: 
#       $myobj->GetKeys( \@mylist )
sub GetKeys
{
	my $self = shift;
	if( @_ != 1 ){
		die 'usage: GetKeys( $arrayref )';
	}

	if (ref $_[0] ne ARRAY){
		die "GetKeys requires a list reference as an arguement";
	}

	local ($Result,$ValueName,$i,$keyname);

	$ValueName="DummyVal";$i=0;
	$Result = 1;
	
	while( $Result ){
		$Result = RegEnumKey( $self->{'handle'},$i++, $keyname );
		if ($Result){
			push( @{$_[0]}, $keyname );
		}
	}
	return(1);

}
#######################################################################
#GetValues
# GetValues creates a hash containing 'name'=> ( name,type,data )
# for each value in the current key.

sub GetValues
{
	my $self = shift;

	if( @_ != 1 ){
		die 'usage: GetValues( $hashref )';
	}

	local ($Result,$ValueName,$i);

	$ValueName="DummyVal";$i=0;
	while( $Result=RegEnumValue( $self->{'handle'},
					$i++,
					$ValueName,
					NULL,
					$ValueType,
					$ValueData )){

		$aref = [ $ValueName, $ValueType,$ValueData ];

		$_[0]->{$ValueName} = $aref;
	}
		
	return(1);
}

#######################################################################
#DeleteKey
# delete a key from the registry.
#  eg: $CLASSES_ROOT->DeleteKey( "KeyNameToDelete");
#

sub DeleteKey
{
	my $self = shift;
	local($Result);
	if( @_ != 1 ){
		die 'usage: DeleteKey( $SubKey )';
	}

	local( $name ) = @_;

	$Result=RegDeleteKey($self->{'handle'},$name);

 	if(!$Result){
		$! = Win32::GetLastError();
	}
	return($Result);

}

#######################################################################
#DeleteValue
# delete a value from the current key in the registry
#  $CLASSES_ROOT->DeleteValue( "\000" );

sub DeleteValue
{
	my $self = shift;
	local( $Result );

	if( @_ != 1 ){
		die 'usage: DeleteValue( $SubKey )';
	}

	local( $name )=@_;
	
	$Result=RegDeleteValue( $self->{'handle'},$name);
	
	if( !$Result){
		$!=Win32::GetLastError();
	}

	return($Result);

}

#######################################################################
#save
#saves the current hive to a file.
#

sub Save
{
	my $self=shift;

	if( @_ != 1 ){
		die 'usage: Save( $FileName )';
	}

	local( $FileName ) = @_;

	$Result=RegSaveKey( $self->{'handle'},$FileName );

	if( !$Result){
		$!=Win32::GetLastError();
	}

	return($Result);
}

#######################################################################
#Load
#loads a saved key from a file.

sub Load
{
	my $self = shift;
	if( @_ != 2 ){
		die 'usage: Load( $SubKey,$FileName )';
	}

	local( $SubKey,$FileName) = @_;

	$Result=RegLoadKey( $self->{'handle'},$SubKey,$FileName);

	if( !$Result){
		$!=Win32::GetLastError();
	}

	return($Result);
}

#######################################################################
#UnLoad
#unloads a registry hive

sub UnLoad
{
	my $self = shift;
	if ( @_ != 1 ) {
		die 'usage: UnLoad( $SubKey )';
	}

	local( $SubKey) = @_;

	$Result=RegUnLoadKey( $self->{'handle'},$SubKey);

	if( !$Result){
		$!=Win32::GetLastError();
	}

	return($Result);
}
#######################################################################

1;
__END__
