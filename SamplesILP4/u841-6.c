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
ILP_Object ilp__m1_3 (ILP_Closure ilp_useless, ILP_Object self1,
		      ILP_Object t2);

struct ILP_Field ILP_object_x_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point_class,
    NULL,
    "x",
    0}}
};

struct ILP_Class3 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    1,
    &ILP_object_x_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_3,
     }}}
};

struct ILP_Method ILP_object_m1_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "m1",
    2,				/* arité */
    2				/* offset */
    }}
};

extern struct ILP_Class3 ILP_object_Point2D_class;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__m1_6 (ILP_Closure ilp_useless, ILP_Object self4,
		      ILP_Object t5);

struct ILP_Field ILP_object_y_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point2D_class,
    &ILP_object_x_field,
    "y",
    1}}
};

struct ILP_Class3 ILP_object_Point2D_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point_class,
    "Point2D",
    2,
    &ILP_object_y_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_6,
     }}}
};

ILP_Object
ilp__m1_3 (ILP_Closure ilp_useless, ILP_Object self1, ILP_Object t2)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[2];
  ilp_CurrentArguments[0] = self1;
  ilp_CurrentArguments[1] = t2;

  {
    {
      ILP_Object ilptmp399;
      ILP_Object ilptmp400;
      {
	ILP_Object ilptmp401;
	ilptmp401 = self1;
	if (ILP_IsA (ilptmp401, Point))
	  {
	    ilptmp399 = ilptmp401->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp399 = ILP_UnknownFieldError ("x", ilptmp401);
	  }
      }
      ilptmp400 = t2;
      return ILP_Times (ilptmp399, ilptmp400);
    }
  }
}

ILP_Object
ilp__m1_6 (ILP_Closure ilp_useless, ILP_Object self4, ILP_Object t5)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_3;
  ILP_Object ilp_CurrentArguments[2];
  ilp_CurrentArguments[0] = self4;
  ilp_CurrentArguments[1] = t5;

  {
    {
      ILP_Object ilptmp402;
      ILP_Object ilptmp403;
      {
	ILP_Object ilptmp404;
	ilptmp404 = self4;
	if (ILP_IsA (ilptmp404, Point2D))
	  {
	    ilptmp402 = ilptmp404->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp402 = ILP_UnknownFieldError ("y", ilptmp404);
	  }
      }
      ilptmp403 = ILP_FindAndCallSuperMethod ();
      return ILP_Times (ilptmp402, ilptmp403);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp405;
    {
      ILP_Object ilptmp406;
      ILP_Object ilptmp407;
      ILP_Object ilptmp408;
      ilptmp407 = ILP_Integer2ILP (10);
      ilptmp408 = ILP_Integer2ILP (42);
      ilptmp406 = ILP_MakeInstance (Point2D);
      ilptmp406->_content.asInstance.field[0] = ilptmp407;
      ilptmp406->_content.asInstance.field[1] = ilptmp408;
      ilptmp405 = ilptmp406;
    }

    {
      ILP_Object pc7 = ilptmp405;
      {
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;
	if (0 == setjmp (new_catcher._jmp_buf))
	  {
	    ILP_establish_catcher (&new_catcher);
	    {
	      ILP_Object ilptmp409;
	      ILP_Object ilptmp410;
	      ilptmp409 = ILP_Integer2ILP (1);
	      {
		ILP_general_function ilptmp411;
		ILP_Object ilptmp412;
		ILP_Object ilptmp413;
		ilptmp412 = pc7;
		ilptmp413 = ILP_Integer2ILP (2);
		ilptmp411 =
		  ILP_find_method (ilptmp412, &ILP_object_m1_method, 2);
		ilptmp410 = ilptmp411 (NULL, ilptmp412, ilptmp413);
	      }
	      return ILP_Plus (ilptmp409, ilptmp410);
	    }
	    ILP_current_exception = NULL;
	  };
	ILP_reset_catcher (current_catcher);
	if (NULL != ILP_current_exception)
	  {
	    if (0 == setjmp (new_catcher._jmp_buf))
	      {
		ILP_establish_catcher (&new_catcher);
		{
		  ILP_Object e8 = ILP_current_exception;
		  ILP_current_exception = NULL;
		  (void) ILP_FALSE;
		}
	      };
	  };
	ILP_reset_catcher (current_catcher);
	if (NULL != ILP_current_exception)
	  {
	    ILP_throw (ILP_current_exception);
	  };
	return ILP_FALSE;
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
