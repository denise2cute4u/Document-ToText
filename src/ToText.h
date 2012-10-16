#include <libwpd/libwpd.h>
#include <libwpd-stream/WPXStreamImplementation.h>
#include <libwps/libwps.h>
#include <magic.h>
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

class ToText
{
	public:
		static std::string mime( const std::string& filename )
		{
			magic_t cookie = magic_open( MAGIC_MIME_TYPE );

			magic_load( cookie, NULL );

			std::string mime = magic_file( cookie, filename.c_str() );

			if ( mime.compare( "Composite Document File V2 Document, No summary info" ) == 0 )
			{
				// this might need revising for .doc(x)
				mime = "application_msworks";
			}
			else if ( mime.compare( "application/octet-stream" ) == 0 )
			{
				// this is a hell of an asumption, but it'll do for now
				mime = "application_wordperfect";
			}
			else
			{
				mime[ mime.find( '/' ) ] = '_';
			}

			return mime;
		}
};

class DOC
{
	public:
		static std::string parse( const std::string& filename ){ return "im a DOC"; }
};

class RTF
{
	public:
		static std::string parse( const std::string& filename ){ return "im an RTF"; }
};

class WPD
{
	public:
		static std::string parse( const std::string& filename )
		{
			WPXFileStream input( filename.c_str() );
			Interface     interface;

			WPDocument::parse( &input, &interface, NULL );

			return interface.ss.str();
		}
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