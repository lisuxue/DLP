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
ILP_Object ilp__longueur_8 (ILP_Closure ilp_useless, ILP_Object self7);

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
     ilp__longueur_8,
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
      ILP_Object ilptmp259;
      ILP_Object ilptmp260;
      {
	ILP_Object ilptmp261;
	ilptmp261 = self1;
	if (ILP_IsA (ilptmp261, Point))
	  {
	    ilptmp259 = ilptmp261->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp259 = ILP_UnknownFieldError ("x", ilptmp261);
	  }
      }
      {
	ILP_Object ilptmp262;
	ilptmp262 = self1;
	if (ILP_IsA (ilptmp262, Point))
	  {
	    ilptmp260 = ilptmp262->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp260 = ILP_UnknownFieldError ("y", ilptmp262);
	  }
      }
      return ILP_Plus (ilptmp259, ilptmp260);
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
      ILP_Object ilptmp263;
      ILP_Object ilptmp264;
      {
	ILP_Object ilptmp265;
	ILP_Object ilptmp266;
	ilptmp265 = z4;
	{
	  ILP_Object ilptmp267;
	  ilptmp267 = self3;
	  if (ILP_IsA (ilptmp267, Point))
	    {
	      ilptmp266 = ilptmp267->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp266 = ILP_UnknownFieldError ("x", ilptmp267);
	    }
	}
	ilptmp263 = ILP_Times (ilptmp265, ilptmp266);
      }
      {
	ILP_Object ilptmp268;
	ILP_Object ilptmp269;
	ilptmp268 = t5;
	{
	  ILP_Object ilptmp270;
	  ilptmp270 = self3;
	  if (ILP_IsA (ilptmp270, Point))
	    {
	      ilptmp269 = ilptmp270->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp269 = ILP_UnknownFieldError ("y", ilptmp270);
	    }
	}
	ilptmp264 = ILP_Times (ilptmp268, ilptmp269);
      }
      return ILP_Plus (ilptmp263, ilptmp264);
    }
  }
}

ILP_Object
ilp__longueur_8 (ILP_Closure ilp_useless, ILP_Object self7)
{
  static ILP_Method ilp_CurrentMethod = &ILP_object_longueur_method;
  static ILP_general_function ilp_SuperMethod = ilp__longueur_2;
  ILP_Object ilp_CurrentArguments[1];
  ilp_CurrentArguments[0] = self7;

  {
    return ILP_Integer2ILP (826);
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp271;
    {
      ILP_Object ilptmp272;
      ILP_Object ilptmp273;
      ILP_Object ilptmp274;
      ILP_Object ilptmp275;
      ilptmp273 = ILP_Integer2ILP (11);
      ilptmp274 = ILP_Integer2ILP (22);
      ilptmp275 = ILP_String2ILP ("red");
      ilptmp272 = ILP_MakeInstance (PointColore);
      ilptmp272->_content.asInstance.field[0] = ilptmp273;
      ilptmp272->_content.asInstance.field[1] = ilptmp274;
      ilptmp272->_content.asInstance.field[2] = ilptmp275;
      ilptmp271 = ilptmp272;
    }

    {
      ILP_Object pc9 = ilptmp271;
      {
	ILP_general_function ilptmp276;
	ILP_Object ilptmp277;
	ilptmp277 = pc9;
	ilptmp276 =
	  ILP_find_method (ilptmp277, &ILP_object_longueur_method, 1);
	return ilptmp276 (NULL, ilptmp277);
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
