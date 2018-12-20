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

extern struct ILP_Class3 ILP_object_Point2Da_class;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__m1_8 (ILP_Closure ilp_useless, ILP_Object self5,
		      ILP_Object ttt6, ILP_Object uuu7);

struct ILP_Field ILP_object_y_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point2Da_class,
    &ILP_object_x_field,
    "y",
    1}}
};

struct ILP_Class3 ILP_object_Point2Da_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point_class,
    "Point2Da",
    2,
    &ILP_object_y_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_8,
     }}}
};

extern struct ILP_Class3 ILP_object_Point3Da_class;
extern struct ILP_Field ILP_object_z_field;
ILP_Object ilp__m1_12 (ILP_Closure ilp_useless, ILP_Object self9,
		       ILP_Object tt10, ILP_Object uu11);

struct ILP_Field ILP_object_z_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point3Da_class,
    &ILP_object_y_field,
    "z",
    2}}
};

struct ILP_Class3 ILP_object_Point3Da_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point2Da_class,
    "Point3Da",
    3,
    &ILP_object_z_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_12,
     }}}
};

extern struct ILP_Class3 ILP_object_Point2Db_class;
extern struct ILP_Field ILP_object_yy_field;
ILP_Object ilp__m1_16 (ILP_Closure ilp_useless, ILP_Object self13,
		       ILP_Object t14, ILP_Object u15);

struct ILP_Field ILP_object_yy_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point2Db_class,
    &ILP_object_x_field,
    "yy",
    1}}
};

struct ILP_Class3 ILP_object_Point2Db_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point_class,
    "Point2Db",
    2,
    &ILP_object_yy_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_16,
     }}}
};

extern struct ILP_Class3 ILP_object_Point3Db_class;
extern struct ILP_Field ILP_object_zz_field;
ILP_Object ilp__m1_20 (ILP_Closure ilp_useless, ILP_Object self17,
		       ILP_Object tt18, ILP_Object uu19);

struct ILP_Field ILP_object_zz_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point3Db_class,
    &ILP_object_yy_field,
    "zz",
    2}}
};

struct ILP_Class3 ILP_object_Point3Db_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point2Db_class,
    "Point3Db",
    3,
    &ILP_object_zz_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_20,
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
      ILP_Object ilptmp536;
      ILP_Object ilptmp537;
      ilptmp536 = tt2;
      {
	ILP_Object ilptmp538;
	ilptmp538 = self1;
	if (ILP_IsA (ilptmp538, Point))
	  {
	    ilptmp537 = ilptmp538->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp537 = ILP_UnknownFieldError ("x", ilptmp538);
	  }
      }
      return ILP_Times (ilptmp536, ilptmp537);
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
      ILP_Object ilptmp539;
      ILP_Object ilptmp540;
      {
	ILP_Object ilptmp541;
	ILP_Object ilptmp542;
	ilptmp541 = uuu7;
	{
	  ILP_Object ilptmp543;
	  ilptmp543 = self5;
	  if (ILP_IsA (ilptmp543, Point2Da))
	    {
	      ilptmp542 = ilptmp543->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp542 = ILP_UnknownFieldError ("y", ilptmp543);
	    }
	}
	ilptmp539 = ILP_Times (ilptmp541, ilptmp542);
      }
      ilptmp540 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp539, ilptmp540);
    }
  }
}

ILP_Object
ilp__m1_12 (ILP_Closure ilp_useless,
	    ILP_Object self9, ILP_Object tt10, ILP_Object uu11)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_8;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self9;
  ilp_CurrentArguments[1] = tt10;
  ilp_CurrentArguments[2] = uu11;

  {
    {
      ILP_Object ilptmp544;
      ILP_Object ilptmp545;
      {
	ILP_Object ilptmp546;
	ilptmp546 = self9;
	if (ILP_IsA (ilptmp546, Point3Da))
	  {
	    ilptmp544 = ilptmp546->_content.asInstance.field[2];
	  }
	else
	  {
	    ilptmp544 = ILP_UnknownFieldError ("z", ilptmp546);
	  }
      }
      ilptmp545 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp544, ilptmp545);
    }
  }
}

ILP_Object
ilp__m1_16 (ILP_Closure ilp_useless,
	    ILP_Object self13, ILP_Object t14, ILP_Object u15)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_4;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self13;
  ilp_CurrentArguments[1] = t14;
  ilp_CurrentArguments[2] = u15;

  {
    {
      ILP_Object ilptmp547;
      ILP_Object ilptmp548;
      {
	ILP_Object ilptmp549;
	ILP_Object ilptmp550;
	ilptmp549 = u15;
	{
	  ILP_Object ilptmp551;
	  ilptmp551 = self13;
	  if (ILP_IsA (ilptmp551, Point2Db))
	    {
	      ilptmp550 = ilptmp551->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp550 = ILP_UnknownFieldError ("yy", ilptmp551);
	    }
	}
	ilptmp547 = ILP_Times (ilptmp549, ilptmp550);
      }
      ilptmp548 = ILP_FindAndCallSuperMethod ();
      return ILP_Times (ilptmp547, ilptmp548);
    }
  }
}

ILP_Object
ilp__m1_20 (ILP_Closure ilp_useless,
	    ILP_Object self17, ILP_Object tt18, ILP_Object uu19)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_16;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self17;
  ilp_CurrentArguments[1] = tt18;
  ilp_CurrentArguments[2] = uu19;

  {
    {
      ILP_Object ilptmp552;
      ILP_Object ilptmp553;
      {
	ILP_Object ilptmp554;
	ilptmp554 = self17;
	if (ILP_IsA (ilptmp554, Point3Db))
	  {
	    ilptmp552 = ilptmp554->_content.asInstance.field[2];
	  }
	else
	  {
	    ilptmp552 = ILP_UnknownFieldError ("zz", ilptmp554);
	  }
      }
      ilptmp553 = ILP_FindAndCallSuperMethod ();
      return ILP_Times (ilptmp552, ilptmp553);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp555;
    ILP_Object ilptmp556;
    {
      ILP_Object ilptmp557;
      ILP_Object ilptmp558;
      ILP_Object ilptmp559;
      ILP_Object ilptmp560;
      ilptmp558 = ILP_Integer2ILP (-2);
      ilptmp559 = ILP_Integer2ILP (100);
      ilptmp560 = ILP_Integer2ILP (23);
      ilptmp557 = ILP_MakeInstance (Point3Da);
      ilptmp557->_content.asInstance.field[0] = ilptmp558;
      ilptmp557->_content.asInstance.field[1] = ilptmp559;
      ilptmp557->_content.asInstance.field[2] = ilptmp560;
      ilptmp555 = ilptmp557;
    }
    {
      ILP_Object ilptmp561;
      ILP_Object ilptmp562;
      ILP_Object ilptmp563;
      ILP_Object ilptmp564;
      ilptmp562 = ILP_Integer2ILP (20);
      ilptmp563 = ILP_Integer2ILP (1);
      ilptmp564 = ILP_Integer2ILP (5);
      ilptmp561 = ILP_MakeInstance (Point3Db);
      ilptmp561->_content.asInstance.field[0] = ilptmp562;
      ilptmp561->_content.asInstance.field[1] = ilptmp563;
      ilptmp561->_content.asInstance.field[2] = ilptmp564;
      ilptmp556 = ilptmp561;
    }

    {
      ILP_Object pc421 = ilptmp555;
      ILP_Object pc222 = ilptmp556;
      {
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;
	if (0 == setjmp (new_catcher._jmp_buf))
	  {
	    ILP_establish_catcher (&new_catcher);
	    {
	      ILP_Object ilptmp565;
	      ILP_Object ilptmp566;
	      {
		ILP_general_function ilptmp567;
		ILP_Object ilptmp568;
		ILP_Object ilptmp569;
		ILP_Object ilptmp570;
		ilptmp568 = pc421;
		ilptmp569 = ILP_Integer2ILP (3);
		ilptmp570 = ILP_Integer2ILP (4);
		ilptmp567 =
		  ILP_find_method (ilptmp568, &ILP_object_m1_method, 3);
		ilptmp565 = ilptmp567 (NULL, ilptmp568, ilptmp569, ilptmp570);
	      }
	      {
		ILP_Object ilptmp571;
		ILP_Object ilptmp572;
		{
		  ILP_general_function ilptmp573;
		  ILP_Object ilptmp574;
		  ILP_Object ilptmp575;
		  ILP_Object ilptmp576;
		  ilptmp574 = pc222;
		  ilptmp575 = ILP_Integer2ILP (2);
		  ilptmp576 = ILP_Integer2ILP (3);
		  ilptmp573 =
		    ILP_find_method (ilptmp574, &ILP_object_m1_method, 3);
		  ilptmp571 =
		    ilptmp573 (NULL, ilptmp574, ilptmp575, ilptmp576);
		}
		ilptmp572 = ILP_Integer2ILP (-170);
		ilptmp566 = ILP_Plus (ilptmp571, ilptmp572);
	      }
	      return ILP_Plus (ilptmp565, ilptmp566);
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
		  ILP_Object e23 = ILP_current_exception;
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
