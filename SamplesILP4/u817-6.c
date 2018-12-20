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
    {
      ILP_Object ilptmp82;
      ILP_Object ilptmp83;
      {
	ILP_Object ilptmp84;
	ilptmp84 = self1;
	if (ILP_IsA (ilptmp84, Point))
	  {
	    ilptmp82 = ilptmp84->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp82 = ILP_UnknownFieldError ("x", ilptmp84);
	  }
      }
      {
	ILP_Object ilptmp85;
	ilptmp85 = self1;
	if (ILP_IsA (ilptmp85, Point))
	  {
	    ilptmp83 = ilptmp85->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp83 = ILP_UnknownFieldError ("y", ilptmp85);
	  }
      }
      return ILP_Plus (ilptmp82, ilptmp83);
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
      ILP_Object ilptmp86;
      ILP_Object ilptmp87;
      {
	ILP_Object ilptmp88;
	ILP_Object ilptmp89;
	ilptmp88 = z4;
	{
	  ILP_Object ilptmp90;
	  ilptmp90 = self3;
	  if (ILP_IsA (ilptmp90, Point))
	    {
	      ilptmp89 = ilptmp90->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp89 = ILP_UnknownFieldError ("x", ilptmp90);
	    }
	}
	ilptmp86 = ILP_Times (ilptmp88, ilptmp89);
      }
      {
	ILP_Object ilptmp91;
	ILP_Object ilptmp92;
	ilptmp91 = t5;
	{
	  ILP_Object ilptmp93;
	  ilptmp93 = self3;
	  if (ILP_IsA (ilptmp93, Point))
	    {
	      ilptmp92 = ilptmp93->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp92 = ILP_UnknownFieldError ("y", ilptmp93);
	    }
	}
	ilptmp87 = ILP_Times (ilptmp91, ilptmp92);
      }
      return ILP_Plus (ilptmp86, ilptmp87);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp94;
    {
      ILP_Object ilptmp95;
      ILP_Object ilptmp96;
      ILP_Object ilptmp97;
      ilptmp96 = ILP_Integer2ILP (2);
      ilptmp97 = ILP_Integer2ILP (3);
      ilptmp95 = ILP_MakeInstance (Point);
      ilptmp95->_content.asInstance.field[0] = ilptmp96;
      ilptmp95->_content.asInstance.field[1] = ilptmp97;
      ilptmp94 = ilptmp95;
    }

    {
      ILP_Object point7 = ilptmp94;
      {
	ILP_general_function ilptmp98;
	ILP_Object ilptmp99;
	ILP_Object ilptmp100;
	ILP_Object ilptmp101;
	ilptmp99 = point7;
	ilptmp100 = ILP_Integer2ILP (2);
	{
	  ILP_general_function ilptmp102;
	  ILP_Object ilptmp103;
	  ilptmp103 = point7;
	  ilptmp102 =
	    ILP_find_method (ilptmp103, &ILP_object_longueur_method, 1);
	  ilptmp101 = ilptmp102 (NULL, ilptmp103);
	}
	ilptmp98 = ILP_find_method (ilptmp99, &ILP_object_m1_method, 3);
	return ilptmp98 (NULL, ilptmp99, ilptmp100, ilptmp101);
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
