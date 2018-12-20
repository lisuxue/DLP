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
      ILP_Object ilptmp44;
      ILP_Object ilptmp45;
      ilptmp44 = z4;
      ilptmp45 = t5;
      return ILP_Plus (ilptmp44, ilptmp45);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp46;
    {
      ILP_Object ilptmp47;
      ILP_Object ilptmp48;
      ILP_Object ilptmp49;
      ilptmp48 = ILP_Integer2ILP (11);
      ilptmp49 = ILP_Integer2ILP (22);
      ilptmp47 = ILP_MakeInstance (Point);
      ilptmp47->_content.asInstance.field[0] = ilptmp48;
      ilptmp47->_content.asInstance.field[1] = ilptmp49;
      ilptmp46 = ilptmp47;
    }

    {
      ILP_Object point7 = ilptmp46;
      {
	ILP_general_function ilptmp50;
	ILP_Object ilptmp51;
	ILP_Object ilptmp52;
	ILP_Object ilptmp53;
	ilptmp51 = point7;
	ilptmp52 = ILP_Integer2ILP (2);
	{
	  ILP_general_function ilptmp54;
	  ILP_Object ilptmp55;
	  ilptmp55 = point7;
	  ilptmp54 =
	    ILP_find_method (ilptmp55, &ILP_object_longueur_method, 1);
	  ilptmp53 = ilptmp54 (NULL, ilptmp55);
	}
	ilptmp50 = ILP_find_method (ilptmp51, &ILP_object_m1_method, 3);
	return ilptmp50 (NULL, ilptmp51, ilptmp52, ilptmp53);
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
