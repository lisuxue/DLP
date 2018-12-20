#include <stdio.h>
#include <stdlib.h>
#include "ilp.h"

/* Global variables */

/* Global prototypes */

/* Global functions */


/* Classes */
ILP_GenerateClass (4);
extern struct ILP_Class4 ILP_object_Point_class;
extern struct ILP_Field ILP_object_x_field;
extern struct ILP_Field ILP_object_y_field;
ILP_Object ilp__longueur_2 (ILP_Closure ilp_useless, ILP_Object self1);
ILP_Object ilp__m1_6 (ILP_Closure ilp_useless, ILP_Object self3,
		      ILP_Object z4, ILP_Object t5);

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

struct ILP_Class4 ILP_object_Point_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Point",
    2,
    &ILP_object_y_field,
    4,
    {ILPm_print,
     ILPm_classOf,
     ilp__longueur_2,
     ilp__m1_6,
     }}}
};

struct ILP_Method ILP_object_longueur_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "longueur",
    1,				/* arité */
    2				/* offset */
    }}
};

struct ILP_Method ILP_object_m1_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Point_class,
    "m1",
    3,				/* arité */
    3				/* offset */
    }}
};

ILP_GenerateClass (3);
extern struct ILP_Class3 ILP_object_Truc_class;
ILP_Object ilp__nexistePas_9 (ILP_Closure ilp_useless, ILP_Object self7,
			      ILP_Object x8);

struct ILP_Class3 ILP_object_Truc_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Object_class,
    "Truc",
    0,
    NULL,
    3,
    {ILPm_print,
     ILPm_classOf,
     ilp__nexistePas_9,
     }}}
};

struct ILP_Method ILP_object_nexistePas_method = {
  &ILP_object_Method_class,
  {{(struct ILP_Class *) &ILP_object_Truc_class,
    "nexistePas",
    2,				/* arité */
    2				/* offset */
    }}
};

ILP_Object
ilp__longueur_2 (ILP_Closure ilp_useless, ILP_Object self1)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_longueur_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self1;

  {
    {
      ILP_Object ilptmp125;
      ILP_Object ilptmp126;
      {
	ILP_Object ilptmp127;
	ilptmp127 = self1;
	if (ILP_IsA (ilptmp127, Point))
	  {
	    ilptmp125 = ilptmp127->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp125 = ILP_UnknownFieldError ("x", ilptmp127);
	  }
      }
      {
	ILP_Object ilptmp128;
	ilptmp128 = self1;
	if (ILP_IsA (ilptmp128, Point))
	  {
	    ilptmp126 = ilptmp128->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp126 = ILP_UnknownFieldError ("y", ilptmp128);
	  }
      }
      return ILP_Plus (ilptmp125, ilptmp126);
    }
  }
}

ILP_Object
ilp__m1_6 (ILP_Closure ilp_useless,
	   ILP_Object self3, ILP_Object z4, ILP_Object t5)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_m1_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[3];
  ilp_CurrentArguments[0] = self3;
  ilp_CurrentArguments[1] = z4;
  ilp_CurrentArguments[2] = t5;

  {
    {
      ILP_Object ilptmp129;
      ILP_Object ilptmp130;
      {
	ILP_Object ilptmp131;
	ILP_Object ilptmp132;
	ilptmp131 = z4;
	{
	  ILP_Object ilptmp133;
	  ilptmp133 = self3;
	  if (ILP_IsA (ilptmp133, Point))
	    {
	      ilptmp132 = ilptmp133->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp132 = ILP_UnknownFieldError ("x", ilptmp133);
	    }
	}
	ilptmp129 = ILP_Times (ilptmp131, ilptmp132);
      }
      {
	ILP_Object ilptmp134;
	ILP_Object ilptmp135;
	ilptmp134 = t5;
	{
	  ILP_Object ilptmp136;
	  ilptmp136 = self3;
	  if (ILP_IsA (ilptmp136, Point))
	    {
	      ilptmp135 = ilptmp136->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp135 = ILP_UnknownFieldError ("y", ilptmp136);
	    }
	}
	ilptmp130 = ILP_Times (ilptmp134, ilptmp135);
      }
      return ILP_Plus (ilptmp129, ilptmp130);
    }
  }
}

ILP_Object
ilp__nexistePas_9 (ILP_Closure ilp_useless, ILP_Object self7, ILP_Object x8)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_nexistePas_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[2];
  ilp_CurrentArguments[0] = self7;
  ilp_CurrentArguments[1] = x8;

  {
    return x8;
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp137;
    {
      ILP_Object ilptmp138;
      ILP_Object ilptmp139;
      ILP_Object ilptmp140;
      ilptmp139 = ILP_Integer2ILP (2);
      ilptmp140 = ILP_Integer2ILP (3);
      ilptmp138 = ILP_MakeInstance (Point);
      ilptmp138->_content.asInstance.field[0] = ilptmp139;
      ilptmp138->_content.asInstance.field[1] = ilptmp140;
      ilptmp137 = ilptmp138;
    }

    {
      ILP_Object point10 = ilptmp137;
      {
	ILP_Object ilptmp141;
	{
	  struct ILP_catcher *current_catcher = ILP_current_catcher;
	  struct ILP_catcher new_catcher;
	  if (0 == setjmp (new_catcher._jmp_buf))
	    {
	      ILP_establish_catcher (&new_catcher);
	      {
		ILP_general_function ilptmp142;
		ILP_Object ilptmp143;
		ILP_Object ilptmp144;
		ilptmp143 = point10;
		ilptmp144 = ILP_Integer2ILP (23);
		ilptmp142 =
		  ILP_find_method (ilptmp143, &ILP_object_nexistePas_method,
				   2);
		ilptmp141 = ilptmp142 (NULL, ilptmp143, ilptmp144);
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
		    ILP_Object e11 = ILP_current_exception;
		    ILP_current_exception = NULL;
		    (void) ILP_TRUE;
		  }
		};
	    };
	  ILP_reset_catcher (current_catcher);
	  if (NULL != ILP_current_exception)
	    {
	      ILP_throw (ILP_current_exception);
	    };
	  ilptmp141 = ILP_FALSE;
	}
	ilptmp141 = ILP_Integer2ILP (819);
	return ilptmp141;
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
