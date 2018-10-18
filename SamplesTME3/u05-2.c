#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object print;
ILP_Object newline;
ILP_Object makeVector;
ILP_Object vectorLength;
ILP_Object vectorGet;

/* Global prototypes */

/* Global functions */


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp32;
    {
      ILP_Object ilptmp33;
      {
	ILP_Object ilptmp34;
	ILP_Object ilptmp35;
	ilptmp34 = ILP_Integer2ILP (5);
	ilptmp35 = ILP_String2ILP ("bonjour");
	ilptmp33 = ILP_make_vector (ilptmp34, ilptmp35);
      }

      {
	ILP_Object v1 = ilptmp33;
	{
	  ILP_Object ilptmp36;
	  {
	    ILP_Object ilptmp37;
	    ILP_Object ilptmp38;
	    ilptmp37 = v1;
	    ilptmp38 = ILP_Integer2ILP (1);
	    ilptmp36 = ILP_vector_get (ilptmp37, ilptmp38);
	  }
	  ilptmp32 = ILP_print (ilptmp36);
	}

      }
    }
    {
      ilptmp32 = ILP_newline ();
    }
    {
      ILP_Object ilptmp39;
      ilptmp39 = ILP_Integer2ILP (2);

      {
	ILP_Object x2 = ilptmp39;
	{
	  ILP_Object ilptmp40;
	  {
	    ILP_Object ilptmp41;
	    ILP_Object ilptmp42;
	    ilptmp41 = ILP_Integer2ILP (10);
	    ilptmp42 = x2;
	    ilptmp40 = ILP_make_vector (ilptmp41, ilptmp42);
	  }

	  {
	    ILP_Object v13 = ilptmp40;
	    {
	      ILP_Object ilptmp43;
	      {
		ILP_Object ilptmp44;
		ilptmp44 = v13;
		ilptmp43 = ILP_vector_length (ilptmp44);
	      }
	      ilptmp32 = ILP_print (ilptmp43);
	    }

	  }
	}

      }
    }
    return ilptmp32;
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
