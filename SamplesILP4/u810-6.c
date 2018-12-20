#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


/* Classes */
ILP_GenerateClass (2);
extern struct ILP_Class2 ILP_object_Point_class;
extern struct ILP_Field ILP_object_x_field;
extern struct ILP_Field ILP_object_y_field;

struct ILP_Field ILP_object_x_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point_class,
    NULL,
    "x",
    0}}
};

struct ILP_Field ILP_object_y_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point_class,
    &ILP_object_x_field,
    "y",
    1}}
};

struct ILP_Class2 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    2,
    &ILP_object_y_field,
    2,
    {ILPm_print,
     ILPm_classOf,
     }}}
};


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp12;
    {
      ILP_Object ilptmp13;
      ILP_Object ilptmp14;
      ILP_Object ilptmp15;
      ilptmp14 = ILP_Integer2ILP (11);
      ilptmp15 = ILP_Integer2ILP (22);
      ilptmp13 = ILP_MakeInstance (Point);
      ilptmp13->_content.asInstance.field[0] = ilptmp14;
      ilptmp13->_content.asInstance.field[1] = ilptmp15;
      ilptmp12 = ilptmp13;
    }

    {
      ILP_Object point1 = ilptmp12;
      {
	ILP_Object ilptmp16;
	{
	  ILP_Object ilptmp17;
	  ILP_Object ilptmp18;
	  ilptmp17 = point1;
	  ilptmp18 = ILP_Integer2ILP (810);
	  if (ILP_IsA (ilptmp17, Point))
	    {
	      ilptmp16 = ilptmp17->_content.asInstance.field[0] = ilptmp18;
	    }
	  else
	    {
	      ilptmp16 = ILP_UnknownFieldError ("x", ilptmp17);
	    }
	}
	{
	  ILP_Object ilptmp19;
	  ilptmp19 = point1;
	  if (ILP_IsA (ilptmp19, Point))
	    {
	      ilptmp16 = ilptmp19->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp16 = ILP_UnknownFieldError ("x", ilptmp19);
	    }
	}
	return ilptmp16;
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
