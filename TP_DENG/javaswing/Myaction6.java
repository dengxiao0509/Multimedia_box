package javaswing;

import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;

//Myaction6.java : definition d'un action qui sert a help;
public class Myaction6 extends AbstractAction {

	private ActionExample obj;
	private static final long serialVersionUID = 1L;


	//constructor
	public  Myaction6(String name,String shortDescription,ActionExample _obj){
		super(name);
		putValue(SHORT_DESCRIPTION,shortDescription);
		//putValue(MNEMONIC_KEY,mnemonic);
		this.obj=_obj;
	}


	public void actionPerformed(ActionEvent e){
		String hel="You have some buttons in the menu <Menu> and in the toolbar:\n\n";
		hel += "<Search Media> : print the detailed information of one media specified by its name;\n\n";
		hel += "<Search Media Group> : list all the names of medias in a media group specified by name of group;\n\n";
		hel += "<Show All> : list all the medias of one type(Photo,Vedio,Film) , specified by name of type;\n\n";
		hel += "<Play> : play a media in the server, specified by name of media.\n\n";
		hel += "<Close> : exit this program.\n\n\n";
		hel += "In the bottom, <Addtext1> and <Addtext2> are used to add two different text to the textarea,\n\n";
		hel += "You can use <Clean> to clean all the text in the textarea.\n\n\n\n";
		hel += "Enjoy!\n";
		obj.textarea.append(hel);
	
	}
}