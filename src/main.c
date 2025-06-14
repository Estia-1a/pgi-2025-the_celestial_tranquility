#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*test*/
#include <estia-image.h>
#include <getopt.h>

#include "features.h"
#include "utils.h"
#include "argsparse.h"

int main(int argc, char **argv) {
  /*To use debug mode : 
   - add --debug: freud.exe --debug -f images/input/image.jpeg
   or 
   - Simply run your compiled project with start button on the blue menu bar at the bottom of the VS Code window.
   */

  /*DO NOT EDIT THIS PART*/
  Config configuration ;
  parse_arguments( argc, argv, &configuration ) ;
  check_debug_mode(configuration);
  check_file();
  /* END */

  /* Use "if ( strncmp( command, <commandname>, 9 ) == 0 )" to check if your <commandname> is called by program.*/
  /* Example with helloworld command
   * If helloworld is a called command: freud.exe -f images/input/image.jpeg -c helloworld 
   */
  if ( strncmp( configuration.command, "helloworld", 10 ) == 0 ) {
    /* helloworld() function is defined in feature.h and implemented in feature.c */
    helloWorld();
  }
  /*
   * TO COMPLETE
   */
  
  
  if ( strncmp( configuration.command, "dimension", 9 ) == 0 ) {
    /* dimension() function is defined in feature.h and implemented in feature.c */
    dimension( configuration.filenames[0] );
}

  if ( strncmp( configuration.command, "first_pixel", 11 ) == 0 ) {
    /* first_pixel() function is defined in feature.h and implemented in feature.c */
    first_pixel(configuration.filenames[0]);
}

  if ( strncmp( configuration.command, "tenth_pixel", 11 ) == 0 ) {
    /* tenth_pixel() function is defined in feature.h and implemented in feature.c */
    tenth_pixel(configuration.filenames[0]);
}

  if ( strncmp( configuration.command, "second_line", 11 ) == 0 ) {
    /* second_line() function is defined in feature.h and implemented in feature.c */
    second_line(configuration.filenames[0]);
}


if ( strncmp( configuration.command, "print_pixel", 11 ) == 0 ) {
  int x = atoi(configuration.arguments[0]);
  int y = atoi(configuration.arguments[1]);
    /* second_line() function is defined in feature.h and implemented in feature.c */
    print_pixel(configuration.filenames[0], x, y);
}

if ( strncmp( configuration.command, "max_pixel",11 ) == 0 ) {
  /*int x = atoi(configuration.arguments[0]);
  int y = atoi(configuration.arguments[1]);*/
  /* second_line() function is defined in feature.h and implemented in feature.c */
    max_pixel(configuration.filenames[0]);
}

if( strncmp( configuration.command, "max_component", 11 ) == 0 ) {
    /*max_component() function is defined in utils.h and implemented in utils.c */
    max_component(configuration.filenames[0],configuration.arguments[0]);
  }

return 0;
}