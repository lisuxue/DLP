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

ILP_Object
ilp__longueur_2 (ILP_Closure ilp_useless, ILP_Object self1)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_longueur_method;
  static ILP_general_function ilp_SuperMethod = NULL;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self1;

  {
    return ILP_Integer2ILP (812);
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
      ILP_Object ilptmp1;
      ILP_Object ilptmp2;
      ilptmp1 = z4;
      ilptmp2 = t5;
      return ILP_Plus (ilptmp1, ilptmp2);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp3;
    {
      ILP_Object ilptmp4;
      ILP_Object ilptmp5;
      ILP_Object ilptmp6;
      ilptmp5 = ILP_Integer2ILP (11);
      ilptmp6 = ILP_Integer2ILP (22);
      ilptmp4 = ILP_MakeInstance (Point);
      ilptmp4->_content.asInstance.field[0] = ilptmp5;
      ilptmp4->_content.asInstance.field[1] = ilptmp6;
      ilptmp3 = ilptmp4;
    }

    {
      ILP_Object point7 = ilptmp3;
      {
	ILP_Object ilptmp7;
	{
	  ILP_general_function ilptmp8;
	  ILP_Object ilptmp9;
	  ilptmp9 = point7;
	  ilptmp8 = ILP_find_method (ilptmp9, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp8 (NULL, ilptmp9);
	}
	{
	  ILP_general_function ilptmp10;
	  ILP_Object ilptmp11;
	  ilptmp11 = point7;
	  ilptmp10 =
	    ILP_find_method (ilptmp11, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp10 (NULL, ilptmp11);
	}
	{
	  ILP_general_function ilptmp12;
	  ILP_Object ilptmp13;
	  ilptmp13 = point7;
	  ilptmp12 =
	    ILP_find_method (ilptmp13, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp12 (NULL, ilptmp13);
	}
	{
	  ILP_general_function ilptmp14;
	  ILP_Object ilptmp15;
	  ilptmp15 = point7;
	  ilptmp14 =
	    ILP_find_method (ilptmp15, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp14 (NULL, ilptmp15);
	}
	{
	  ILP_general_function ilptmp16;
	  ILP_Object ilptmp17;
	  ilptmp17 = point7;
	  ilptmp16 =
	    ILP_find_method (ilptmp17, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp16 (NULL, ilptmp17);
	}
	{
	  ILP_general_function ilptmp18;
	  ILP_Object ilptmp19;
	  ilptmp19 = point7;
	  ilptmp18 =
	    ILP_find_method (ilptmp19, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp18 (NULL, ilptmp19);
	}
	{
	  ILP_general_function ilptmp20;
	  ILP_Object ilptmp21;
	  ilptmp21 = point7;
	  ilptmp20 =
	    ILP_find_method (ilptmp21, &ILP_object_longueur_method, 1);
	  ilptmp7 = ilptmp20 (NULL, ilptmp21);
	}
	return ilptmp7;
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