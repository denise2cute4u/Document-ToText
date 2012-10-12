#include "WPS.h"
#include <libwpd/WPXDocumentInterface.h>
#include <libwpd-stream/WPXStreamImplementation.h>
#include <libwps/libwps.h>
#include <sstream>
#include <stdio.h>
#include <string>

class Interface : public WPXDocumentInterface
{
	private:
		unsigned short i;

	public:
		         Interface(){}
		virtual ~Interface(){}
		virtual void closeComment(){}
		virtual void closeEndnote(){}
		virtual void closeFooter(){}
		virtual void closeFootnote(){}
		virtual void closeFrame(){}
		virtual void closeHeader(){}
		virtual void closeOrderedListLevel(){}
		virtual void closePageSpan(){}
		virtual void closeSection(){}
		virtual void closeSpan(){}
		virtual void closeTable(){}
		virtual void closeTableCell(){}
		virtual void closeTableRow(){}
		virtual void closeTextBox(){}
		virtual void closeUnorderedListLevel(){}
		virtual void defineCharacterStyle( const WPXPropertyList& ){}
		virtual void defineOrderedListLevel( const WPXPropertyList& ){}
		virtual void definePageStyle( const WPXPropertyList& ){}
		virtual void defineParagraphStyle( const WPXPropertyList&, const WPXPropertyListVector& ){}
		virtual void defineSectionStyle( const WPXPropertyList&, const WPXPropertyListVector& ){}
		virtual void defineUnorderedListLevel( const WPXPropertyList& ){}
		virtual void endDocument(){}
		virtual void insertBinaryObject( const WPXPropertyList&, const WPXBinaryData& ){}
		virtual void insertCoveredTableCell( const WPXPropertyList& ){}
		virtual void insertEquation( const WPXPropertyList&, const WPXString& ){}
		virtual void insertField( const WPXString&, const WPXPropertyList& ){}
		virtual void openComment( const WPXPropertyList& ){}
		virtual void openEndnote( const WPXPropertyList& ){}
		virtual void openFooter( const WPXPropertyList& ){}
		virtual void openFootnote( const WPXPropertyList& ){}
		virtual void openFrame( const WPXPropertyList& ){}
		virtual void openHeader( const WPXPropertyList& ){}
		virtual void openPageSpan( const WPXPropertyList& ){}
		virtual void openParagraph( const WPXPropertyList&, const WPXPropertyListVector& ){}
		virtual void openSection( const WPXPropertyList&, const WPXPropertyListVector& ){}
		virtual void openSpan( const WPXPropertyList& ){}
		virtual void openTable( const WPXPropertyList&, const WPXPropertyListVector& ){}
		virtual void openTableCell( const WPXPropertyList& ){}
		virtual void openTableRow( const WPXPropertyList& ){}
		virtual void openTextBox( const WPXPropertyList& ){}
		virtual void openUnorderedListLevel( const WPXPropertyList& ){}
		virtual void setDocumentMetaData( const WPXPropertyList& ){}
		virtual void startDocument(){}

		std::stringstream ss;

		virtual void closeListElement()                             { ss << "\n";        }
		virtual void closeParagraph()                               { ss << "\n";        }
		virtual void insertLineBreak()                              { ss << "\n";        }
		virtual void insertSpace()                                  { ss <<  " ";        }
		virtual void insertTab()                                    { ss << "\t";        }
		virtual void insertText(      const WPXString& txt         ){ ss << txt.cstr();  }
		virtual void openListElement( const WPXPropertyList&,
		                              const WPXPropertyListVector& ){ ss << ++i << ". "; }
		virtual void openOrderedListLevel( const WPXPropertyList&  ){ i = 0;             }
};

std::string WPS::parse( const std::string& filename )
{
	WPXFileStream input( filename.c_str() );
	Interface     interface;

	WPSDocument::parse( &input, &interface );

	return interface.ss.str();
}