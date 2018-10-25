/* *****************************************************************
 * ilp2 - Implantation d'un langage de programmation.
 * by Christian.Queinnec@paracamplus.com
 * See http://mooc.paracamplus.com/ilp2
 * GPL version 3
 ***************************************************************** */
package com.paracamplus.ilp2.ilp2tme4.ex3.compiler.normalizer;

import com.paracamplus.ilp2.ilp2tme4.ex3.ast.ASTunless;
import com.paracamplus.ilp1.interfaces.IASTexpression;

public class NormalizationFactory
extends com.paracamplus.ilp2.compiler.normalizer.NormalizationFactory
implements INormalizationFactory {
    
    
    @Override
	public IASTexpression newUnless(IASTexpression condition, IASTexpression  body) {
        return new ASTunless(condition, body);
    }
 
}
