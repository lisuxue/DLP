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

extern struct ILP_Class3 ILP_object_Point4D_class;
extern struct ILP_Field ILP_object_t_field;
ILP_Object ilp__m1_16 (ILP_Closure ilp_useless, ILP_Object self13,
		       ILP_Object tt14, ILP_Object uu15);

struct ILP_Field ILP_object_t_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_Point4D_class,
    &ILP_object_z_field,
    "t",
    3}}
};

struct ILP_Class3 ILP_object_Point4D_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point3D_class,
    "Point4D",
    4,
    &ILP_object_t_field,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__m1_16,
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
      ILP_Object ilptmp504;
      ILP_Object ilptmp505;
      ilptmp504 = tt2;
      {
	ILP_Object ilptmp506;
	ilptmp506 = self1;
	if (ILP_IsA (ilptmp506, Point))
	  {
	    ilptmp505 = ilptmp506->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp505 = ILP_UnknownFieldError ("x", ilptmp506);
	  }
      }
      return ILP_Times (ilptmp504, ilptmp505);
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
      ILP_Object ilptmp507;
      ILP_Object ilptmp508;
      {
	ILP_Object ilptmp509;
	ILP_Object ilptmp510;
	ilptmp509 = uuu7;
	{
	  ILP_Object ilptmp511;
	  ilptmp511 = self5;
	  if (ILP_IsA (ilptmp511, Point2D))
	    {
	      ilptmp510 = ilptmp511->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp510 = ILP_UnknownFieldError ("y", ilptmp511);
	    }
	}
	ilptmp507 = ILP_Times (ilptmp509, ilptmp510);
      }
      ilptmp508 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp507, ilptmp508);
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
      ILP_Object ilptmp512;
      ilptmp512 = self9;
      if (ILP_IsA (ilptmp512, Point3D))
	{
	  return ilptmp512->_content.asInstance.field[2];
	}
      else
	{
	  return ILP_UnknownFieldError ("z", ilptmp512);
	}
    }
  }
}

ILP_Object
ilp__m1_16 (ILP_Closure ilp_useless,
	    ILP_Object self13, ILP_Object tt14, ILP_Object uu15)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = ilp__m1_12;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self13;
  ilp_CurrentArguments[1] = tt14;
  ilp_CurrentArguments[2] = uu15;

  {
    {
      ILP_Object ilptmp513;
      ILP_Object ilptmp514;
      {
	ILP_Object ilptmp515;
	ilptmp515 = self13;
	if (ILP_IsA (ilptmp515, Point4D))
	  {
	    ilptmp513 = ilptmp515->_content.asInstance.field[3];
	  }
	else
	  {
	    ilptmp513 = ILP_UnknownFieldError ("t", ilptmp515);
	  }
      }
      ilptmp514 = ILP_FindAndCallSuperMethod ();
      return ILP_Plus (ilptmp513, ilptmp514);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp516;
    ILP_Object ilptmp517;
    {
      ILP_Object ilptmp518;
      ILP_Object ilptmp519;
      ILP_Object ilptmp520;
      ILP_Object ilptmp521;
      ILP_Object ilptmp522;
      ilptmp519 = ILP_Integer2ILP (-1);
      ilptmp520 = ILP_Integer2ILP (-2);
      ilptmp521 = ILP_Integer2ILP (400);
      ilptmp522 = ILP_Integer2ILP (16);
      ilptmp518 = ILP_MakeInstance (Point4D);
      ilptmp518->_content.asInstance.field[0] = ilptmp519;
      ilptmp518->_content.asInstance.field[1] = ilptmp520;
      ilptmp518->_content.asInstance.field[2] = ilptmp521;
      ilptmp518->_content.asInstance.field[3] = ilptmp522;
      ilptmp516 = ilptmp518;
    }
    {
      ILP_Object ilptmp523;
      ILP_Object ilptmp524;
      ILP_Object ilptmp525;
      ilptmp524 = ILP_Integer2ILP (20);
      ilptmp525 = ILP_Integer2ILP (1);
      ilptmp523 = ILP_MakeInstance (Point2D);
      ilptmp523->_content.asInstance.field[0] = ilptmp524;
      ilptmp523->_content.asInstance.field[1] = ilptmp525;
      ilptmp517 = ilptmp523;
    }

    {
      ILP_Object pc417 = ilptmp516;
      ILP_Object pc218 = ilptmp517;
      {
	struct ILP_catcher *current_catcher = ILP_current_catcher;
	struct ILP_catcher new_catcher;
	if (0 == setjmp (new_catcher._jmp_buf))
	  {
	    ILP_establish_catcher (&new_catcher);
	    {
	      ILP_Object ilptmp526;
	      ILP_Object ilptmp527;
	      {
		ILP_general_function ilptmp528;
		ILP_Object ilptmp529;
		ILP_Object ilptmp530;
		ILP_Object ilptmp531;
		ilptmp529 = pc417;
		ilptmp530 = ILP_Integer2ILP (-3);
		ilptmp531 = ILP_Integer2ILP (-4);
		ilptmp528 =
		  ILP_find_method (ilptmp529, &ILP_object_m1_method, 3);
		ilptmp526 = ilptmp528 (NULL, ilptmp529, ilptmp530, ilptmp531);
	      }
	      {
		ILP_general_function ilptmp532;
		ILP_Object ilptmp533;
		ILP_Object ilptmp534;
		ILP_Object ilptmp535;
		ilptmp533 = pc218;
		ilptmp534 = ILP_Integer2ILP (20);
		ilptmp535 = ILP_Integer2ILP (30);
		ilptmp532 =
		  ILP_find_method (ilptmp533, &ILP_object_m1_method, 3);
		ilptmp527 = ilptmp532 (NULL, ilptmp533, ilptmp534, ilptmp535);
	      }
	      return ILP_Plus (ilptmp526, ilptmp527);
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
		  ILP_Object e19 = ILP_current_exception;
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
