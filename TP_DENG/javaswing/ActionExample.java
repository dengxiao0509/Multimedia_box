package javaswing;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.io.InputStreamReader;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;
import javax.swing.border.BevelBorder;


public class ActionExample extends JFrame 
implements ActionListener{

	private static final long serialVersionUID = 1L;

	private	Myaction1 myaction1;
	private Myaction2 myaction2;
	private Myaction3 myaction3;
	private Myaction4 myaction4;
	private Myaction5 myaction5;
	private Myaction6 myaction6;
	//	ImageIcon icon1,icon2,icon_close;


	JMenuBar menubar=new JMenuBar();
	JMenu menu=new JMenu("Menu");
	JMenu help=new JMenu("Help");
	JToolBar toolbar=new JToolBar();
	JPanel jpanel=new JPanel();
	JPanel jpanel_bt=new JPanel();
	JButton addtext1_bt,addtext2_bt,clean_bt;
	JTextArea textarea=new JTextArea(20,40);	
	JTextField nmedia= new JTextField();
	
	
	Client _client;

	//constructor
	public ActionExample(Client c){
		this._client=c;
		
				
		setLayout(new BorderLayout());

		//creat icons for the toolbar
		/*icon1=new ImageIcon(ActionExample.class.getResource(""));
		icon2=new ImageIcon(ActionExample.class.getResource(""));
		icon_close=new ImageIcon(ActionExample.class.getResource(""));		
		 */


		//create three Action objects
		//create  action by using new Myaction1
		//Actionadd1(String name,String shortDescription,Interger mnemonic,ActionExample _obj)
		myaction1=new Myaction1("Search Media","This button is used to search a media.",this);
		myaction2=new Myaction2("Search Media Group","This button is used to list medias of a media group.",this);
		myaction3=new Myaction3("Close","This button is used to exit.");
		myaction4=new Myaction4("Show All","This button is used to show all medias of one type specified.",this);
		myaction5=new Myaction5("Play","This button is used to play a media",this);
		myaction6=new Myaction6("How to use","This button is used to tell you how to use this tool",this);

		//Add a jpanel and construct a textarea and a scrollpane over it
		jpanel.add(textarea);
		this.add(jpanel,BorderLayout.CENTER);
		textarea.setEditable(false);
				
		JScrollPane scrollPane=new JScrollPane(textarea);
		jpanel.add(scrollPane,BorderLayout.EAST);


		//Construct and decorate the memu 
		menubar.add(menu);
		menubar.add(help);
		//setBorder method: to cause its edges to become visible
		menubar.setBorder(new BevelBorder(BevelBorder.RAISED));
		this.setJMenuBar(menubar);

		//Construct and add the toolbar
		toolbar.setBorder(new BevelBorder(BevelBorder.RAISED));
		//JPanel panel=new JPanel();
		//panel.add(toolbar,BorderLayout.PAGE_START);
		//this.add(panel,BorderLayout.NORTH);
		add(toolbar,BorderLayout.NORTH);



		//create menu items and connect their Action
		JMenu searchsub=new JMenu("Search");
		menu.add(searchsub);
		
		
		JMenuItem addtext1=new JMenuItem("Search Media");
		addtext1.setAction((javax.swing.Action) myaction1);
		searchsub.add(addtext1);
		//or set its Action objet in the constructor
		JMenuItem addtext2=new JMenuItem("Search Media Group");
		addtext2.setAction((javax.swing.Action) myaction2);
		searchsub.add(addtext2);

		JMenuItem sa=new JMenuItem("Show All");
		sa.setAction((javax.swing.Action) myaction4);
		menu.add(sa);
		//or set its Action objet in the constructor
		JMenuItem pl=new JMenuItem("Play Media");
		pl.setAction((javax.swing.Action) myaction5);
		menu.add(pl);
		
		JMenuItem close=new JMenuItem();
		close.setAction((javax.swing.Action) myaction3);
		menu.add(close);
		
			
		JMenuItem htu=new JMenuItem();
		htu.setAction(myaction6);
		help.add(htu);

	
		

		//create toolbar buttons
		JButton addtext1button=new JButton("search media");
		addtext1button.setAction((javax.swing.Action) myaction1);
		JButton addtext2button=new JButton("search media group");
		addtext2button.setAction((javax.swing.Action) myaction2);
		JButton sabutton=new JButton("show all");
		sabutton.setAction((javax.swing.Action) myaction4);
		JButton plbutton=new JButton("play");
		plbutton.setAction((javax.swing.Action) myaction5);
		JButton closebutton=new JButton("close");
		closebutton.setAction((javax.swing.Action) myaction3);
		

		//add buttons to the toolbar
		toolbar.add(addtext1button);
		toolbar.add(addtext2button);
		toolbar.add(sabutton);
		toolbar.add(plbutton);
		toolbar.add(closebutton);



		//create buttons

		addtext1_bt=new JButton ("Addtext1");
		addtext2_bt=new JButton ("Addtext2");
		clean_bt=new JButton("Clean");

		jpanel_bt.add(addtext1_bt);
		jpanel_bt.add(addtext2_bt);
		jpanel_bt.add(clean_bt);
		this.add(jpanel_bt,BorderLayout.SOUTH);		
		//this.setContentPane(panel);
		addtext1_bt.addActionListener(this);
		addtext2_bt.addActionListener(this);
		clean_bt.addActionListener(this);
		
	

		//setSize(400,500);
		//setBackground(Color.orange);
		setTitle("Client of multimedia");
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		pack();
		setVisible(true);


	}
	public void actionPerformed(ActionEvent e){
	
		if(e.getSource()==addtext1_bt){
			
			textarea.append("Today is a sunny day, so I go out for a picnic with my families, I am very very very very very very very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very very happy :)\n");
			
		}


		else if(e.getSource()==addtext2_bt){
			textarea.append("Tomorrow is going to rain, and I can't go hiking with my friends, so I'm totally very very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very veryvery very very very very sad :(\n");
		}
		else if(e.getSource()==clean_bt){
			textarea.setText("");
		}
	}

}
