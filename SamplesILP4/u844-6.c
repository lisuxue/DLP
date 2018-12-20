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
ILP_Object ilp__m1_4 (ILP_Closure ilp_useless, ILP_Object self1,
		      ILP_Object u2, ILP_Object t3);

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

extern struct ILP_Class3 ILP_object_Point2D_class;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__m1_8 (ILP_Closure ilp_useless, ILP_Object self5,
		      ILP_Object t6, ILP_Object u7);

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
     ilp__m1_8,
     }}}
};

extern struct ILP_Class3 ILP_object_Point3D_class;
extern struct ILP_Field ILP_object_z_field;
ILP_Object ilp__m1_12 (ILP_Closure ilp_useless, ILP_Object self9,
		       ILP_Object t10, ILP_Object u11);

struct ILP_Field ILP_object_z_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point3D_class,
    &ILP_object_y_field,
    "z",
    2}}
};

struct ILP_Class3 ILP_object_Point3D_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point2D_class,
    "Point3D",
    3,
    &ILP_object_z_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_12,
     }}}
};

ILP_Object
ilp__m1_4 (ILP_Closure ilp_useless,
	   ILP_Object self1, ILP_Object u2, ILP_Object t3)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self1;
  ilp_CurrentArguments[1] = u2;
  ilp_CurrentArguments[2] = t3;

  {
    {
      ILP_Object ilptmp448;
      ILP_Object ilptmp449;
      ilptmp448 = u2;
      {
	ILP_Object ilptmp450;
	ilptmp450 = self1;
	if (ILP_IsA (ilptmp450, Point))
	  {
	    ilptmp449 = ilptmp450->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp449 = ILP_UnknownFieldError ("x", ilptmp450);
	  }
      }
      return ILP_Times (ilptmp448, ilptmp449);
    }
  }
}

ILP_Object
ilp__m1_8 (ILP_Closure ilp_useless,
	   ILP_Object self5, ILP_Object t6, ILP_Object u7)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_4;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self5;
  ilp_CurrentArguments[1] = t6;
  ilp_CurrentArguments[2] = u7;

  {
    {
      ILP_Object ilptmp451;
      ILP_Object ilptmp452;
      {
	ILP_Object ilptmp453;
	ILP_Object ilptmp454;
	ilptmp453 = u7;
	{
	  ILP_Object ilptmp455;
	  ilptmp455 = self5;
	  if (ILP_IsA (ilptmp455, Point2D))
	    {
	      ilptmp454 = ilptmp455->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp454 = ILP_UnknownFieldError ("y", ilptmp455);
	    }
	}
	ilptmp451 = ILP_Times (ilptmp453, ilptmp454);
      }
      ilptmp452 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp451, ilptmp452);
    }
  }
}

ILP_Object
ilp__m1_12 (ILP_Closure ilp_useless,
	    ILP_Object self9, ILP_Object t10, ILP_Object u11)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_8;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self9;
  ilp_CurrentArguments[1] = t10;
  ilp_CurrentArguments[2] = u11;

  {
    {
      ILP_Object ilptmp456;
      ILP_Object ilptmp457;
      {
	ILP_Object ilptmp458;
	ilptmp458 = self9;
	if (ILP_IsA (ilptmp458, Point3D))
	  {
	    ilptmp456 = ilptmp458->_content.asInstance.field[2];
	  }
	else
	  {
	    ilptmp456 = ILP_UnknownFieldError ("z", ilptmp458);
	  }
      }
      ilptmp457 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp456, ilptmp457);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp459;
    {
      ILP_Object ilptmp460;
      ILP_Object ilptmp461;
      ILP_Object ilptmp462;
      ILP_Object ilptmp463;
      ilptmp461 = ILP_Integer2ILP (400);
      ilptmp462 = ILP_Integer2ILP (10);
      ilptmp463 = ILP_Integer2ILP (14);
      ilptmp460 = ILP_MakeInstance (Point3D);
      ilptmp460->_content.asInstance.field[0] = ilptmp461;
      ilptmp460->_content.asInstance.field[1] = ilptmp462;
      ilptmp460->_content.asInstance.field[2] = ilptmp463;
      ilptmp459 = ilptmp460;
    }

    {
      ILP_Object pc13 = ilptmp459;
      {
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;
	if (0 == setjmp (new_catcher._jmp_buf))
	  {
	    ILP_establish_catcher (&new_catcher);
	    {
	      ILP_general_function ilptmp464;
	      ILP_Object ilptmp465;
	      ILP_Object ilptmp466;
	      ILP_Object ilptmp467;
	      ilptmp465 = pc13;
	      ilptmp466 = ILP_Integer2ILP (2);
	      ilptmp467 = ILP_Integer2ILP (3);
	      ilptmp464 =
		ILP_find_method (ilptmp465, &ILP_object_m1_method, 3);
	      return ilptmp464 (NULL, ilptmp465, ilptmp466, ilptmp467);
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
		  ILP_Object e14 = ILP_current_exception;
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
