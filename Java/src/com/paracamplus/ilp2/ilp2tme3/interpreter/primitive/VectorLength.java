/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;



import java.util.ArrayList;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.Primitive;

public class VectorLength extends Primitive { 
    
    public VectorLength() {
        super("vectorLength");
    }
        
    @Override
	public Object apply (Object vector) throws EvaluationException {
        if (vector instanceof ArrayList) {
        	@SuppressWarnings("unchecked")
			ArrayList<Object> v = (ArrayList<Object>)vector;
        	return v.size();
        }
        throw new EvaluationException("Le paramètre passé à sinus n'est pas valide.");
    }

	@Override
	public int getArity() {
		// TODO Auto-generated method stub
		return 1;
	}
}
