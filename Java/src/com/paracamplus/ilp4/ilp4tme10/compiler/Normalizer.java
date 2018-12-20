/* *****************************************************************
 * ilp4 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp4
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp4.ilp4tme10.compiler;

import com.paracamplus.ilp1.compiler.CompilationException;
import com.paracamplus.ilp1.compiler.normalizer.INormalizationEnvironment;
import com.paracamplus.ilp1.interfaces.IASTexpression;
import com.paracamplus.ilp4.compiler.interfaces.IASTCclassDefinition;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTexists;
import com.paracamplus.ilp4.ilp4tme10.interfaces.IASTvisitor;

public class Normalizer 
extends com.paracamplus.ilp4.compiler.normalizer.Normalizer 
implements 
 IASTvisitor<IASTexpression, INormalizationEnvironment, CompilationException> {


    public Normalizer (INormalizationFactory factory,
                       IASTCclassDefinition objectClass ) {
    	super(factory, objectClass);
    }

	@Override
	public IASTexpression visit(IASTexists iast, INormalizationEnvironment data) throws CompilationException {
		return ((INormalizationFactory)factory).newExists(iast.getVarName());
	}
}
