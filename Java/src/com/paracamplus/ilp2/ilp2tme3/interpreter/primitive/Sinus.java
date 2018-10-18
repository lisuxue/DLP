/* *****************************************************************
 * ILP9 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp9
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme3.interpreter.primitive;


import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

import com.paracamplus.ilp1.interpreter.interfaces.EvaluationException;
import com.paracamplus.ilp1.interpreter.primitive.UnaryPrimitive;

public class Sinus extends UnaryPrimitive { //sinus de ILP prend en arg des radians
    
    public Sinus() {
        super("sinus");
    }
        
    @Override
	public Object apply (Object value) throws EvaluationException {
        if (value instanceof BigDecimal) {
        	BigDecimal v = (BigDecimal)value;
        	return new BigDecimal(Math.sin(v.doubleValue()), MathContext.DECIMAL64);
        }
        if (value instanceof BigInteger) {
        	BigInteger v = (BigInteger)value;
        	return new BigDecimal(Math.sin(v.doubleValue()), MathContext.DECIMAL64);
        }
        throw new EvaluationException("Le paramètre passé à sinus n'est pas valide.");
    }
}
