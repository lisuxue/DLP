#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


/* Classes */
ILP_GenerateClass (3);
extern struct ILP_Class3 ILP_object_Point_class;
extern struct ILP_Field ILP_object_x_field;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__m1_4 (ILP_Closure ilp_useless, ILP_Object self1,
		      ILP_Object z2, ILP_Object t3);

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

struct ILP_Class3 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    2,
    &ILP_object_y_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_4,
     }}}
};

struct ILP_Method ILP_object_m1_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "m1",
    3,				/* arité */
    2				/* offset */
    }}
};

ILP_Object
ilp__m1_4 (ILP_Closure ilp_useless,
	   ILP_Object self1, ILP_Object z2, ILP_Object t3)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self1;
  ilp_CurrentArguments[1] = z2;
  ilp_CurrentArguments[2] = t3;

  {
    {
      ILP_Object ilptmp66;
      ILP_Object ilptmp67;
      {
	ILP_Object ilptmp68;
	ILP_Object ilptmp69;
	ilptmp68 = z2;
	{
	  ILP_Object ilptmp70;
	  ilptmp70 = self1;
	  if (ILP_IsA (ilptmp70, Point))
	    {
	      ilptmp69 = ilptmp70->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp69 = ILP_UnknownFieldError ("x", ilptmp70);
	    }
	}
	ilptmp66 = ILP_Times (ilptmp68, ilptmp69);
      }
      {
	ILP_Object ilptmp71;
	ILP_Object ilptmp72;
	ilptmp71 = t3;
	{
	  ILP_Object ilptmp73;
	  ilptmp73 = self1;
	  if (ILP_IsA (ilptmp73, Point))
	    {
	      ilptmp72 = ilptmp73->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp72 = ILP_UnknownFieldError ("y", ilptmp73);
	    }
	}
	ilptmp67 = ILP_Times (ilptmp71, ilptmp72);
      }
      return ILP_Plus (ilptmp66, ilptmp67);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp74;
    {
      ILP_Object ilptmp75;
      ILP_Object ilptmp76;
      ILP_Object ilptmp77;
      ilptmp76 = ILP_Integer2ILP (2);
      ilptmp77 = ILP_Integer2ILP (3);
      ilptmp75 = ILP_MakeInstance (Point);
      ilptmp75->_content.asInstance.field[0] = ilptmp76;
      ilptmp75->_content.asInstance.field[1] = ilptmp77;
      ilptmp74 = ilptmp75;
    }

    {
      ILP_Object point5 = ilptmp74;
      {
	ILP_general_function ilptmp78;
	ILP_Object ilptmp79;
	ILP_Object ilptmp80;
	ILP_Object ilptmp81;
	ilptmp79 = point5;
	ilptmp80 = ILP_Integer2ILP (2);
	ilptmp81 = ILP_Integer2ILP (3);
	ilptmp78 = ILP_find_method (ilptmp79, &ILP_object_m1_method, 3);
	return ilptmp78 (NULL, ilptmp79, ilptmp80, ilptmp81);
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
