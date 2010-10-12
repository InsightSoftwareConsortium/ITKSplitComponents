#include "SplitComponentsArgs.h"

#include "metaCommand.h"

Args::Args( int argc, char* argv[] )
{
  MetaCommand command;
  command.SetDescription(
    "Convert an itk::Image of vectors, covariant vectors,\
 or symmetric second rank tensors into its components." );
  command.SetAuthor( "Matthew McCormick" );

  command.AddField( "inputImage", "Input image.", MetaCommand::STRING, MetaCommand::DATA_IN);

  command.SetOption( "outputPrefix", "o", false, "Output image prefix.  Optional." );
  command.SetOptionLongTag( "outputPrefix", "output" );
  command.AddOptionField( "outputPrefix", "outputPrefix", MetaCommand::STRING, true, "", "", MetaCommand::DATA_OUT );

  if( !command.Parse( argc, argv ) )
    {
    if( command.GotXMLFlag() )
      throw got_xml_flag_exception( "Passed in --xml" );
    else
      throw std::logic_error( "Could not parse command line arguments." );
    }

  if( !command.GetOptionWasSet( "inputImage" ) )
    throw std::runtime_error( "Input image not specified." );
  this->inputImage = command.GetValueAsString( "inputImage" );

  if( !command.GetOptionWasSet( "outputPrefix" ) )
    {
    // truncate the input extension
    std::string fileBase = this->inputImage;
    size_t      fileBaseLength = fileBase.length();
    if ( fileBaseLength > 4 )
      {
      if ( !this->inputImage.compare(fileBaseLength - 4, 1, ".") )
        {
        fileBase = fileBase.substr(0, fileBaseLength - 4);
        }
      }
    this->outputPrefix = fileBase;
    }
  else
    this->outputPrefix = command.GetValueAsString( "outputPrefix", "outputPrefix" );
}
