//
// IBM AntiVirus Immune System
//
// File Name: ZExcept.cpp
// Author:    Milosz Muszynski
//
// Class ZExceptionTranslator translates Windows system exceptions
// to exceptions belonging to the ZException class hierarchy
//
// $Log: $
//



//------ pragmas ------------------------------------------------------
#pragma warning( disable : 4786 ) // identifier truncated warning 

// ------ standard includes -----------------------------------------------------------
#include <string>

// ------ local includes --------------------------------------------------------------
#include "ZExcept.h"


//
// ZException constructor
//

ZException::ZException( const std::string& text, unsigned int code, int line, const std::string& file )
    : _text(text), _code( code ), _line(line), _file(file)
{
}


//
// ZExceptionTranslator
//

// the rest of this file is not portable

#ifdef WIN32

void SEH_TransFunction( unsigned int nCode, _EXCEPTION_POINTERS *pExp )
{
    throw ZSystemException( std::string( "SE cought" ), nCode, __LINE__, __FILE__ );
}

void ZExceptionTranslator::init()
{
    if ( !_translatorSet )
    {
        _oldTranslatorFunction = _set_se_translator( SEH_TransFunction );
        _translatorSet = true;
    }
}

ZExceptionTranslator::~ZExceptionTranslator()
{
    if ( _translatorSet )
        _set_se_translator( _oldTranslatorFunction );
}

#endif // WIN32



