/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;


import java.math.BigInteger;
import java.util.ArrayList;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;

public class MakeVector extends Primitive { 
    
    public MakeVector() {
        super("makeVector");
    }
        
    @Override
	public Object apply (Object size, Object value) throws EvaluationException {
       if (size instanceof BigInteger) {
    	   BigInteger s = (BigInteger)size;
    	   ArrayList<Object> vector = new ArrayList<Object>(s.intValue());
    	   for (int i=0; i<s.intValue();i++) {
    		   vector.add(value);
    	   }
    	   return vector;
       }else {
    	   throw new EvaluationException("Le premier paramètre doit être un entier indiquant la taille du vecteur.");
       }
    }

	@Override
	public int getArity() {
		return 2;
	}
}
