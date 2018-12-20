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
      ILP_Object ilptmp174;
      ILP_Object ilptmp175;
      {
	ILP_Object ilptmp176;
	ilptmp176 = self1;
	if (ILP_IsA (ilptmp176, Point))
	  {
	    ilptmp174 = ilptmp176->_content.asInstance.field[0];
	  }
	else
	  {
	    ilptmp174 = ILP_UnknownFieldError ("x", ilptmp176);
	  }
      }
      {
	ILP_Object ilptmp177;
	ilptmp177 = self1;
	if (ILP_IsA (ilptmp177, Point))
	  {
	    ilptmp175 = ilptmp177->_content.asInstance.field[1];
	  }
	else
	  {
	    ilptmp175 = ILP_UnknownFieldError ("y", ilptmp177);
	  }
      }
      return ILP_Plus (ilptmp174, ilptmp175);
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
      ILP_Object ilptmp178;
      ILP_Object ilptmp179;
      {
	ILP_Object ilptmp180;
	ILP_Object ilptmp181;
	ilptmp180 = z4;
	{
	  ILP_Object ilptmp182;
	  ilptmp182 = self3;
	  if (ILP_IsA (ilptmp182, Point))
	    {
	      ilptmp181 = ilptmp182->_content.asInstance.field[0];
	    }
	  else
	    {
	      ilptmp181 = ILP_UnknownFieldError ("x", ilptmp182);
	    }
	}
	ilptmp178 = ILP_Times (ilptmp180, ilptmp181);
      }
      {
	ILP_Object ilptmp183;
	ILP_Object ilptmp184;
	ilptmp183 = t5;
	{
	  ILP_Object ilptmp185;
	  ilptmp185 = self3;
	  if (ILP_IsA (ilptmp185, Point))
	    {
	      ilptmp184 = ilptmp185->_content.asInstance.field[1];
	    }
	  else
	    {
	      ilptmp184 = ILP_UnknownFieldError ("y", ilptmp185);
	    }
	}
	ilptmp179 = ILP_Times (ilptmp183, ilptmp184);
      }
      return ILP_Plus (ilptmp178, ilptmp179);
    }
  }
}


ILP_Object
ilp_program ()
{
  {
    ILP_Object ilptmp186;
    {
      ILP_Object ilptmp187;
      ILP_Object ilptmp188;
      ILP_Object ilptmp189;
      ILP_Object ilptmp190;
      ilptmp188 = ILP_Integer2ILP (11);
      ilptmp189 = ILP_Integer2ILP (22);
      ilptmp190 = ILP_String2ILP ("red");
      ilptmp187 = ILP_MakeInstance (PointColore);
      ilptmp187->_content.asInstance.field[0] = ilptmp188;
      ilptmp187->_content.asInstance.field[1] = ilptmp189;
      ilptmp187->_content.asInstance.field[2] = ilptmp190;
      ilptmp186 = ilptmp187;
    }

    {
      ILP_Object pc7 = ilptmp186;
      {
	ILP_Object ilptmp191;
	{
	  ILP_Object ilptmp192;
	  ILP_Object ilptmp193;
	  ilptmp192 = pc7;
	  ilptmp193 = ILP_Integer2ILP (822);
	  if (ILP_IsA (ilptmp192, PointColore))
	    {
	      ilptmp191 = ilptmp192->_content.asInstance.field[2] = ilptmp193;
	    }
	  else
	    {
	      ilptmp191 = ILP_UnknownFieldError ("color", ilptmp192);
	    }
	}
	{
	  ILP_Object ilptmp194;
	  ilptmp194 = pc7;
	  if (ILP_IsA (ilptmp194, PointColore))
	    {
	      ilptmp191 = ilptmp194->_content.asInstance.field[2];
	    }
	  else
	    {
	      ilptmp191 = ILP_UnknownFieldError ("color", ilptmp194);
	    }
	}
	return ilptmp191;
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
