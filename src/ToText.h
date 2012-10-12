#include <libwpd/WPXDocumentInterface.h>
#include <libwpd-stream/WPXStreamImplementation.h>
#include <libwps/libwps.h>
#include <sstream>
#include <string>

class Interface :public WPXDocumentInterface
{
	private:
		unsigned short i;

	public:
		     Interface(){}
		    ~Interface(){}
		void closeComment(){}
		void closeEndnote(){}
		void closeFooter(){}
		void closeFootnote(){}
		void closeFrame(){}
		void closeHeader(){}
		void closeOrderedListLevel(){}
		void closePageSpan(){}
		void closeSection(){}
		void closeSpan(){}
		void closeTable(){}
		void closeTableCell(){}
		void closeTableRow(){}
		void closeTextBox(){}
		void closeUnorderedListLevel(){}
		void defineCharacterStyle( const WPXPropertyList& ){}
		void defineOrderedListLevel( const WPXPropertyList& ){}
		void definePageStyle( const WPXPropertyList& ){}
		void defineParagraphStyle( const WPXPropertyList&, const WPXPropertyListVector& ){}
		void defineSectionStyle( const WPXPropertyList&, const WPXPropertyListVector& ){}
		void defineUnorderedListLevel( const WPXPropertyList& ){}
		void endDocument(){}
		void insertBinaryObject( const WPXPropertyList&, const WPXBinaryData& ){}
		void insertCoveredTableCell( const WPXPropertyList& ){}
		void insertEquation( const WPXPropertyList&, const WPXString& ){}
		void insertField( const WPXString&, const WPXPropertyList& ){}
		void openComment( const WPXPropertyList& ){}
		void openEndnote( const WPXPropertyList& ){}
		void openFooter( const WPXPropertyList& ){}
		void openFootnote( const WPXPropertyList& ){}
		void openFrame( const WPXPropertyList& ){}
		void openHeader( const WPXPropertyList& ){}
		void openPageSpan( const WPXPropertyList& ){}
		void openParagraph( const WPXPropertyList&, const WPXPropertyListVector& ){}
		void openSection( const WPXPropertyList&, const WPXPropertyListVector& ){}
		void openSpan( const WPXPropertyList& ){}
		void openTable( const WPXPropertyList&, const WPXPropertyListVector& ){}
		void openTableCell( const WPXPropertyList& ){}
		void openTableRow( const WPXPropertyList& ){}
		void openTextBox( const WPXPropertyList& ){}
		void openUnorderedListLevel( const WPXPropertyList& ){}
		void setDocumentMetaData( const WPXPropertyList& ){}
		void startDocument(){}

		std::stringstream ss;

		void closeListElement()                             { ss << "\n";        }
		void closeParagraph()                               { ss << "\n";        }
		void insertLineBreak()                              { ss << "\n";        }
		void insertSpace()                                  { ss <<  " ";        }
		void insertTab()                                    { ss << "\t";        }
		void insertText(      const WPXString& txt         ){ ss << txt.cstr();  }
		void openListElement( const WPXPropertyList&,
		                      const WPXPropertyListVector& ){ ss << ++i << ". "; }
		void openOrderedListLevel( const WPXPropertyList&  ){ i = 0;             }
};

class DOC
{
	public:
		static std::string parse( const std::string& filename ){ return filename; }
};

class RTF
{
	public:
		static std::string parse( const std::string& filename ){ return filename; }
};

class WPS
{
	public:
		static std::string parse( const std::string& filename )
		{
			WPXFileStream input( filename.c_str() );
			Interface     interface;

			WPSDocument::parse( &input, &interface );

			return interface.ss.str();
		}
};