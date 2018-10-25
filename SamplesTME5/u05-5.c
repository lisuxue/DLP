#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */
ILP_Object a;
ILP_Object print;

/* Global prototypes */
ILP_Object ilp__a (ILP_Closure ilp_useless, ILP_Object x1);

/* Global functions */

ILP_Object
ilp__a (ILP_Closure ilp_useless, ILP_Object x1)
{
  {
    ILP_Object ilptmp33;
    ILP_Object ilptmp34;
    ilptmp33 = ILP_Integer2ILP (2);
    ilptmp34 = x1;
    return ILP_Times (ilptmp33, ilptmp34);
  }
}

struct ILP_Closure a_closure_object = {
  &ILP_object_Closure_class,
  {{ilp__a,
    1,
    {NULL}}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp35;
    ilptmp35 = ILP_Integer2ILP (2);

    {
      ILP_Object y2 = ilptmp35;
      {
	ILP_Object ilptmp36;
	{
	  ILP_Object ilptmp37;
	  ilptmp37 = y2;
	  ilptmp36 = ilp__a (NULL, ilptmp37);
	}
	return ILP_print (ilptmp36);
      }

    }
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
