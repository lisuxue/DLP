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
      ILP_Object ilptmp157;
      ILP_Object ilptmp158;
      {
	ILP_Object ilptmp159;
	ilptmp159 = self1;
	if (ILP_IsA (ilptmp159, Point))
	  {
	    ilptmp157 = ilptmp159->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp157 = ILP_UnknownFieldError ("x", ilptmp159);
	  }
      }
      {
	ILP_Object ilptmp160;
	ilptmp160 = self1;
	if (ILP_IsA (ilptmp160, Point))
	  {
	    ilptmp158 = ilptmp160->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp158 = ILP_UnknownFieldError ("y", ilptmp160);
	  }
      }
      return ILP_Plus (ilptmp157, ilptmp158);
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
      ILP_Object ilptmp161;
      ILP_Object ilptmp162;
      {
	ILP_Object ilptmp163;
	ILP_Object ilptmp164;
	ilptmp163 = z4;
	{
	  ILP_Object ilptmp165;
	  ilptmp165 = self3;
	  if (ILP_IsA (ilptmp165, Point))
	    {
	      ilptmp164 = ilptmp165->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp164 = ILP_UnknownFieldError ("x", ilptmp165);
	    }
	}
	ilptmp161 = ILP_Times (ilptmp163, ilptmp164);
      }
      {
	ILP_Object ilptmp166;
	ILP_Object ilptmp167;
	ilptmp166 = t5;
	{
	  ILP_Object ilptmp168;
	  ilptmp168 = self3;
	  if (ILP_IsA (ilptmp168, Point))
	    {
	      ilptmp167 = ilptmp168->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp167 = ILP_UnknownFieldError ("y", ilptmp168);
	    }
	}
	ilptmp162 = ILP_Times (ilptmp166, ilptmp167);
      }
      return ILP_Plus (ilptmp161, ilptmp162);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp169;
    {
      ILP_Object ilptmp170;
      ILP_Object ilptmp171;
      ILP_Object ilptmp172;
      ILP_Object ilptmp173;
      ilptmp171 = ILP_Integer2ILP (11);
      ilptmp172 = ILP_Integer2ILP (22);
      ilptmp173 = ILP_String2ILP ("red");
      ilptmp170 = ILP_MakeInstance (PointColore);
      ilptmp170->_content.asInstance.field[0] = ilptmp171;
      ilptmp170->_content.asInstance.field[1] = ilptmp172;
      ilptmp170->_content.asInstance.field[2] = ilptmp173;
      ilptmp169 = ilptmp170;
    }
    ilptmp169 = ILP_Integer2ILP (821);
    return ilptmp169;
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
