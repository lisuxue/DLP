#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;
ILP_Object newline;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp14;
    {
      ILP_Object ilptmp15;
      ilptmp15 = ILP_Integer2ILP (10);

      {
	ILP_Object z1 = ilptmp15;
	{
	  ILP_Object ilptmp16;
	  ilptmp16 = z1;
	  ilptmp14 = ILP_print (ilptmp16);
	}

      }
    }
    {
      ilptmp14 = ILP_newline ();
    }
    ilptmp14 = ILP_String2ILP ("bonjour");
    {
      ILP_Object ilptmp17;
      ILP_Object ilptmp18;
      ilptmp17 = ILP_Integer2ILP (2);
      ilptmp18 = ILP_Integer2ILP (3);

      {
	ILP_Object x2 = ilptmp17;
	ILP_Object y3 = ilptmp18;
	{
	  ILP_Object ilptmp19;
	  ILP_Object ilptmp20;
	  ilptmp19 = x2;
	  ilptmp20 = y3;
	  ilptmp14 = ILP_Plus (ilptmp19, ilptmp20);
	}

      }
    }
    {
      ILP_Object ilptmp21;
      {
	ILP_Object ilptmp22;
	ilptmp22 = ILP_TRUE;
	if (ILP_isEquivalentToTrue (ilptmp22))
	  {
	    {
	      ILP_Object ilptmp23;
	      ILP_Object ilptmp24;
	      {
		ILP_Object ilptmp25;
		ILP_Object ilptmp26;
		ilptmp25 = ILP_Integer2ILP (1);
		ilptmp26 = ILP_Integer2ILP (2);
		ilptmp23 = ILP_Plus (ilptmp25, ilptmp26);
	      }
	      ilptmp24 = ILP_Integer2ILP (3);
	      ilptmp21 = ILP_Plus (ilptmp23, ilptmp24);
	    }

	  }
	else
	  {
	    {
	      ILP_Object ilptmp27;
	      ILP_Object ilptmp28;
	      ilptmp27 = ILP_Integer2ILP (2);
	      ilptmp28 = ILP_Integer2ILP (2);
	      ilptmp21 = ILP_Plus (ilptmp27, ilptmp28);
	    }

	  }
      }

      {
	ILP_Object a4 = ilptmp21;
	{
	  ILP_Object ilptmp29;
	  ilptmp29 = a4;
	  ilptmp14 = ILP_print (ilptmp29);
	}

      }
    }
    return ilptmp14;
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
