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
		      ILP_Object tt2, ILP_Object uu3);

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
		      ILP_Object ttt6, ILP_Object uuu7);

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
	   ILP_Object self1, ILP_Object tt2, ILP_Object uu3)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self1;
  ilp_CurrentArguments[1] = tt2;
  ilp_CurrentArguments[2] = uu3;

  {
    {
      ILP_Object ilptmp468;
      ILP_Object ilptmp469;
      ilptmp468 = tt2;
      {
	ILP_Object ilptmp470;
	ilptmp470 = self1;
	if (ILP_IsA (ilptmp470, Point))
	  {
	    ilptmp469 = ilptmp470->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp469 = ILP_UnknownFieldError ("x", ilptmp470);
	  }
      }
      return ILP_Times (ilptmp468, ilptmp469);
    }
  }
}

ILP_Object
ilp__m1_8 (ILP_Closure ilp_useless,
	   ILP_Object self5, ILP_Object ttt6, ILP_Object uuu7)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_4;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self5;
  ilp_CurrentArguments[1] = ttt6;
  ilp_CurrentArguments[2] = uuu7;

  {
    {
      ILP_Object ilptmp471;
      ILP_Object ilptmp472;
      {
	ILP_Object ilptmp473;
	ILP_Object ilptmp474;
	ilptmp473 = uuu7;
	{
	  ILP_Object ilptmp475;
	  ilptmp475 = self5;
	  if (ILP_IsA (ilptmp475, Point2D))
	    {
	      ilptmp474 = ilptmp475->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp474 = ILP_UnknownFieldError ("y", ilptmp475);
	    }
	}
	ilptmp471 = ILP_Times (ilptmp473, ilptmp474);
      }
      ilptmp472 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp471, ilptmp472);
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
      ILP_Object ilptmp476;
      ILP_Object ilptmp477;
      {
	ILP_Object ilptmp478;
	ilptmp478 = self9;
	if (ILP_IsA (ilptmp478, Point3D))
	  {
	    ilptmp476 = ilptmp478->_content.asInstance.field[2];
	  }
	else
	  {
	    ilptmp476 = ILP_UnknownFieldError ("z", ilptmp478);
	  }
      }
      ilptmp477 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp476, ilptmp477);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp479;
    {
      ILP_Object ilptmp480;
      ILP_Object ilptmp481;
      ILP_Object ilptmp482;
      ILP_Object ilptmp483;
      ilptmp481 = ILP_Integer2ILP (400);
      ilptmp482 = ILP_Integer2ILP (10);
      ilptmp483 = ILP_Integer2ILP (15);
      ilptmp480 = ILP_MakeInstance (Point3D);
      ilptmp480->_content.asInstance.field[0] = ilptmp481;
      ilptmp480->_content.asInstance.field[1] = ilptmp482;
      ilptmp480->_content.asInstance.field[2] = ilptmp483;
      ilptmp479 = ilptmp480;
    }

    {
      ILP_Object pc13 = ilptmp479;
      {
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;
	if (0 == setjmp (new_catcher._jmp_buf))
	  {
	    ILP_establish_catcher (&new_catcher);
	    {
	      ILP_general_function ilptmp484;
	      ILP_Object ilptmp485;
	      ILP_Object ilptmp486;
	      ILP_Object ilptmp487;
	      ilptmp485 = pc13;
	      ilptmp486 = ILP_Integer2ILP (2);
	      ilptmp487 = ILP_Integer2ILP (3);
	      ilptmp484 =
		ILP_find_method (ilptmp485, &ILP_object_m1_method, 3);
	      return ilptmp484 (NULL, ilptmp485, ilptmp486, ilptmp487);
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
