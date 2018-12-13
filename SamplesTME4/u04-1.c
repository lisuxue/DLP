#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp7;
    {
      ILP_Object ilptmp8;
      ilptmp8 = ILP_Integer2ILP (10);

      {
	ILP_Object z1 = ilptmp8;
	{
	  ILP_Object ilptmp9;
	  ilptmp9 = z1;
	  ilptmp7 = ILP_print (ilptmp9);
	}

      }
    }
    {
      ILP_Object ilptmp10;
      ILP_Object ilptmp11;
      ilptmp10 = ILP_Integer2ILP (2);
      ilptmp11 = ILP_Integer2ILP (3);

      {
	ILP_Object x2 = ilptmp10;
	ILP_Object y3 = ilptmp11;
	{
	  ILP_Object ilptmp12;
	  ILP_Object ilptmp13;
	  ilptmp12 = x2;
	  ilptmp13 = y3;
	  ilptmp7 = ILP_Plus (ilptmp12, ilptmp13);
	}

      }
    }
    return ilptmp7;
  }

}

static ILP_Object
ilp_caught_program ()
{
  struct ILP_catcher *current_catcher = ILP_current_catcher;
  struct ILP_catcher new_catcher;

  if (0 == setjmp (new_catcher._jmp_buf))
    {
      ILP_establish_catcher (&new_catcher);
      return ilp_program ();
    };
  return ILP_current_exception;
}

int
main (int argc, char *argv[])
{
  ILP_START_GC;
  ILP_print (ilp_caught_program ());
  ILP_newline ();
  return EXIT_SUCCESS;
}
