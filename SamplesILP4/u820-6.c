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

extern struct ILP_Class4 ILP_object_PointColore_class;
extern struct ILP_Field ILP_object_color_field;

struct ILP_Field ILP_object_color_field = {
  &ILP_object_Field_class,
  {{(ILP_Class) & ILP_object_PointColore_class,
    &ILP_object_y_field,
    "color",
    2}}
};

struct ILP_Class4 ILP_object_PointColore_class = {
  &ILP_object_Class_class,
  {{(ILP_Class) & ILP_object_Point_class,
    "PointColore",
    3,
    &ILP_object_color_field,
    4,
    {ILPm_print,
     ILPm_classOf,
     ilp__longueur_2,
     ilp__m1_6,
     }}}
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
      ILP_Object ilptmp145;
      ILP_Object ilptmp146;
      {
	ILP_Object ilptmp147;
	ilptmp147 = self1;
	if (ILP_IsA (ilptmp147, Point))
	  {
	    ilptmp145 = ilptmp147->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp145 = ILP_UnknownFieldError ("x", ilptmp147);
	  }
      }
      {
	ILP_Object ilptmp148;
	ilptmp148 = self1;
	if (ILP_IsA (ilptmp148, Point))
	  {
	    ilptmp146 = ilptmp148->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp146 = ILP_UnknownFieldError ("y", ilptmp148);
	  }
      }
      return ILP_Plus (ilptmp145, ilptmp146);
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
      ILP_Object ilptmp149;
      ILP_Object ilptmp150;
      {
	ILP_Object ilptmp151;
	ILP_Object ilptmp152;
	ilptmp151 = z4;
	{
	  ILP_Object ilptmp153;
	  ilptmp153 = self3;
	  if (ILP_IsA (ilptmp153, Point))
	    {
	      ilptmp152 = ilptmp153->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp152 = ILP_UnknownFieldError ("x", ilptmp153);
	    }
	}
	ilptmp149 = ILP_Times (ilptmp151, ilptmp152);
      }
      {
	ILP_Object ilptmp154;
	ILP_Object ilptmp155;
	ilptmp154 = t5;
	{
	  ILP_Object ilptmp156;
	  ilptmp156 = self3;
	  if (ILP_IsA (ilptmp156, Point))
	    {
	      ilptmp155 = ilptmp156->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp155 = ILP_UnknownFieldError ("y", ilptmp156);
	    }
	}
	ilptmp150 = ILP_Times (ilptmp154, ilptmp155);
      }
      return ILP_Plus (ilptmp149, ilptmp150);
    }
  }
}


ILP_Object
ilp_program ()
{
  return ILP_Integer2ILP (820);

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
