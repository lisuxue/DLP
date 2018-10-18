package com.paracamplus.ilp1.ilp1tme1.factory;

/*Cette nouvelle classe hérite de l'ancienne classe ASTFactory 
 * en redefinissant la méthode newSequence : on utilise ici nouvelle version de sequence
 * mais au niveau des imports comment ça marche ? 
 * si il y a override pour deux import similaire ? 
 * 
 *
 * */

/*import com.paracamplus.ilp1.ast.ASTsequence;*/
import com.paracamplus.ilp1.interfaces.IASTexpression;
/*import com.paracamplus.ilp1.interfaces.IASTsequence;*/
import com.paracamplus.ilp1.ilp1tme1.sequence.IASTsequence;
import com.paracamplus.ilp1.ilp1tme1.sequence.ASTsequence;;

public class ASTfactory extends com.paracamplus.ilp1.ast.ASTfactory{

	@Override
	public IASTsequence newSequence(IASTexpression[] asts) {
        return new ASTsequence(asts);
    }
	
}
