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

public class VectorGet extends Primitive { 
    
    public VectorGet() {
        super("vectorGet");
    }
        
    @Override
	public Object apply (Object vector, Object position) throws EvaluationException {
	       if (position instanceof BigInteger && vector instanceof ArrayList) {
	    	   BigInteger p = (BigInteger)position;
	    	   @SuppressWarnings("unchecked")
	    	   ArrayList<Object> v = (ArrayList<Object>)vector;
	    	   return v.get(p.intValue());
	       }else {
	    	   throw new EvaluationException("Le premier paramètre doit être un ArrayList, et le deuxième doit être "
	    	   		+ "entier indiquant la position de "
	    	   		+ "l'élément demandé.");
	       }
    }

	@Override
	public int getArity() {
		// TODO Auto-generated method stub
		return 2;
	}
}
