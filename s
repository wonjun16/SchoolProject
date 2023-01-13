
import java.awt.EventQueue;
import javax.swing.JFrame;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;

import javax.swing.JToolBar;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextArea;
import javax.swing.JComboBox;
import javax.swing.JTextPane;
import javax.swing.JSeparator;
import javax.swing.JOptionPane;
import javax.swing.JList;
import javax.swing.JDialog;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JScrollPane;
import java.awt.Font;
import java.awt.FontMetrics;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;
import com.sun.tools.javac.Main;
import javax.swing.JFormattedTextField;
import java.sql.*;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import javax.swing.Action;
import javax.swing.Icon;
import javax.swing.ImageIcon;

public class PostWindow extends JFrame{

	public JPanel postPanel;
	private JTextField likeNum;
	private JTextField searchTextArea;
	private JTextField idTextArea;
	Data so = new Data();
	String[][] postValue = so.getPost();
	String[][] followers = so.getFollowers();
	Container container = getContentPane();
	
	JPanel p = new JPanel(); //follower瑜� �닃���쓣 �븣 follower�쓽 寃뚯떆湲�留� �몴�떆�븯湲� �쐞�븳 �뙣�꼸

	/**
	 * Create the application.
	 */
	public PostWindow(String myId, String id, String post, String post_title) {
		super("Twitter");
		setSize(650, 800);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setVisible(true);
		initialize(myId, id, post, post_title);
		
	}

	/**
	 * Initialize the contents of the postFrame.
	 */
	// 濡쒓렇�씤 --> mainUI --> post源뚯� �쟾�떖�릺�뼱�빞�븷 myId,
	// mainUI 寃뚯떆臾쇰쭏�떎 ���옣�릺�뼱 �엳�뒗 寃뚯떆�옄�쓽 id, post, post_title �젙蹂� 媛��졇�삤湲�
	// 洹쇰뜲 id, post, postTile �꼫臾� 蹂듭옟�빐�꽌 post留덈떎 援щ텇�븷 �닔 �엳�뒗 postNum �엳�뒗寃� �굹�쓣 寃� 媛숈쓬...
	private void initialize(String myId, String id, String post, String post_title) {
		// 媛��졇�삱 �슂�냼 珥덇린�솕
		String postTitle = null;
		String postContent = null;
		String postComment = null;
		int postlike = 0;
		
		// DB connection
		DBConnection DBcon = new DBConnection();
		DBcon.connect();
		
		// 寃뚯떆臾� �꽑�깮�븷 �븣�쓽 id, post�궡�슜, postTitle �젙蹂댁� 媛숈� �뻾�뱾�쓣 select.
		String postQuery = String.format("select * from post where id = '%s' and post = '%s' and postTitle = '%s';", id, post, post_title);
		try{
			Statement poststmt = DBcon.connection.createStatement();
			ResultSet postResult = poststmt.executeQuery(postQuery);
			while (postResult.next()) {
				postTitle = postResult.getString("postTitle");
				postContent = postResult.getString("post");
				postlike = postResult.getInt("likeNum");
				postComment = postResult.getString("comments");
			}
			DBcon.connection.close();
		}catch(SQLException SQLE) {
			SQLE.printStackTrace();
		}
		
	    String heart = new String(Character.toChars(10084));
	    String msg = heart;
	    
		
		//湲곕낯 �뙣�꼸 �꽕�젙
		container.setLayout(null);
		container.setBackground(new Color(230, 255, 255));
		
		JPanel pnlWest = new JPanel();
		JPanel postPanel = new JPanel();
		JPanel pnlEast = new JPanel();
		JPanel pnlNorth = new JPanel();
		
		pnlNorth.setBounds(0, 0, 636, 80);
		pnlWest.setBounds(10, 100, 90, 650);
		pnlEast.setBounds(450, 100, 180, 650);
		postPanel.setBounds(120, 100, 310, 650);
		
		pnlNorth.setLayout(null);
		pnlWest.setLayout(null);
		pnlEast.setLayout(null);
		postPanel.setLayout(null);
		
		postPanel.setBackground(new Color(29,161,243));
		pnlNorth.setBackground(new Color(255, 255, 255));
		pnlWest.setBackground(new Color(255, 255, 255));
		pnlEast.setBackground(new Color(255, 255, 255));
		
		container.add(pnlNorth);
		container.add(pnlEast);
		container.add(pnlWest);
		container.add(postPanel);
		
		LineBorder line = new LineBorder(new Color(85, 135, 237), 2, true);
		LineBorder line1 = new LineBorder(new Color(85, 135, 237), 2, true);
		LineBorder line2 = new LineBorder(new Color(85, 135, 237), 2, true);
		LineBorder line3 = new LineBorder(new Color(0, 44, 145), 2, true);
		pnlNorth.setBorder(line);
		pnlEast.setBorder(line2);
		pnlWest.setBorder(line1);
		postPanel.setBorder(line3);
		
		//North 而댄룷�꼳�듃
		JLabel page = new JLabel("TWITTER");
		JTextField searchField = new JTextField();
		RoundedButton btnSearch = new RoundedButton("SEARCH");
		btnSearch.setBackground(Color.WHITE);
		btnSearch.setForeground(new Color(29,161,243));
		btnSearch.setBounds(430, 25, 60, 30);
		btnSearch.addActionListener(new ActionListener(){
			public void actionPerformed(ActionEvent e) {
				String search = searchField.getText();
				DBConnection DBcon = new DBConnection();
				DBcon.connect();
				String query = "select * from post where postTitle like '%" + search + "%'";
				try {
					Statement stmt = DBcon.connection.createStatement();
					ResultSet result = stmt.executeQuery(query);
					while(result.next()) {
						System.out.println(result.getString("id"));
						System.out.println(result.getInt("likeNum"));
						System.out.println(result.getString("comments"));
						System.out.println(result.getString("post"));
						System.out.println(result.getString("postTitle"));
						System.out.println(result.getString("postTime"));
					}
					DBcon.connection.close();
				}catch(SQLException SQLE) {
					SQLE.printStackTrace();
				}
			}
		});

		searchField.setBounds(490, 25, 130, 30);
		page.setBounds(230, 10, 120, 60);
		page.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
		
		pnlNorth.add(page);
		pnlNorth.add(searchField);	
		pnlNorth.add(btnSearch);
		
		//West 而댄룷�꼳�듃
		RoundedButton home = new RoundedButton("HOME");
		RoundedButton postbtn = new RoundedButton("POST");
		
		home.setBounds(5, 10, 80, 30);
		postbtn.setBounds(5, 50, 80, 30);
		postbtn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				dia subFrame = new dia(myId);
				subFrame.diaFrame.setVisible(true);
			}
		});
		
		home.setBackground(new Color(29,161,243));
		postbtn.setBackground(new Color(29,161,243));
		home.setForeground(Color.WHITE);
		postbtn.setForeground(Color.WHITE);
		
		home.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
			}
		});
		
		pnlWest.add(home);
		pnlWest.add(postbtn);
		
		//East 而댄룷�꼳�듃
		int j = 0;
		
		while(followers[j][0]!=null) {
			
			if(followers[j][0].equals(myId)) {
				
				RoundedButton follower = new RoundedButton();
				follower.setText(followers[j][1]);
				follower.setBounds(50, 20+40*j, 80, 30);
				follower.setBackground(Color.WHITE);
				follower.setForeground(new Color(29,161,243));
				follower.addActionListener(new ActionListener() {
					
					@Override
					public void actionPerformed(ActionEvent e) {
						postPanel.setVisible(false);
						
						p.removeAll();
						
						LineBorder line4 = new LineBorder(new Color(0, 44, 145), 2, true);
						p.setBorder(line4);
						p.setLayout(null);
						p.setBounds(120, 100, 310, 650);
						p.setBackground(new Color(29,161,243));
						
						int i = 0;
						int postLoc = 0;
						//寃뚯떆湲� �몴�떆
						while(postValue[i][0]!=null) {
							
							if(follower.getText().equals(postValue[i][1])) {
								
								RoundedButton btnPost = new RoundedButton();
								btnPost.setBackground(Color.WHITE);
								btnPost.setText(postValue[i][0]);
								btnPost.setBounds(2, 2+(postLoc*120), 306, 100);
								btnPost.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
								p.add(btnPost);
								postLoc += 1;
								
							}
							
							i += 1;
							
						}
						
						container.add(p);
						
					}
				});
				
				pnlEast.add(follower);
				
			}
				j += 1;
				
//			}
//		postFrame = new JFrame();
//		postFrame.setBounds(0, 0, 900, 700);
//		postFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//		postFrame.getContentPane().setLayout(null);
//		
//		
//	    JPanel postPanel = new JPanel();
//	    postPanel.setBounds(120, 100, 310, 650);
//	    postPanel.setBackground(new Color(29,161,243));
//	    LineBorder line3 = new LineBorder(new Color(0, 44, 145), 2, true);
//	    postPanel.setBorder(line3);
//		postPanel.setLayout(null);
		
		// post �궡�슜遺�遺�
		JTextArea postTextArea = new JTextArea(100, 100);
		postTextArea.setBounds(0, 52, 500, 200);
		postTextArea.setWrapStyleWord(true);
		postTextArea.setText(postContent);
		postTextArea.setFont(new Font("Comic Sans MS", Font.BOLD, 13));
		postTextArea.setEditable(false);
		postPanel.add(postTextArea);
		
		// �뙎湲�
		JTextArea commentsTextArea = new JTextArea();
		
		JScrollPane commentsScrollPane = new JScrollPane(commentsTextArea, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_NEVER);
		commentsScrollPane.setBounds(0, 294, 500, 305);
		postPanel.add(commentsScrollPane);
		commentsScrollPane.setViewportView(commentsTextArea);
		commentsTextArea.setText(postComment);
		commentsTextArea.setFont(new Font("Comic Sans MS", Font.BOLD, 20));
		commentsTextArea.setEditable(false);
		
		// 寃뚯떆臾� �쐞�뿉 �늻媛� �삱�졇�뒗吏��뿉 ���븳 �젙蹂�...
		ImageIcon img = new ImageIcon("./src/user.png");
		JPanel profilePanel = new JPanel();
		profilePanel.setBounds(0, 0, 500, 53);
		postPanel.add(profilePanel);
		profilePanel.setLayout(null);
		
		// 湲곕낯 �봽濡쒗븘 �씠誘몄� 踰꾪듉�쑝濡� �떖�뼱�넃�� 寃�
		JButton ImageButton = new JButton(img);
		ImageButton.setHorizontalAlignment(SwingConstants.LEFT);
		ImageButton.setBounds(0, 0, 100, 53);
		ImageButton.setBorderPainted(false);
		ImageButton.setContentAreaFilled(false);
		ImageButton.setFocusPainted(false);
		profilePanel.setBackground(new Color(29,161,243));
		profilePanel.add(ImageButton);
		
		// 寃뚯떆臾� �늻媛� �삱�졇�뒗吏�
		idTextArea = new JTextField();
		idTextArea.setBounds(109, 10, 100, 33);
		profilePanel.add(idTextArea);
		idTextArea.setColumns(10);
		idTextArea.setFont(new Font("Comic Sans MS", Font.BOLD, 13));
		idTextArea.setText(id);
		
		// follow 踰꾪듉
		JButton followButton = new JButton("+");
		followButton.setHorizontalAlignment(SwingConstants.LEFT);
		followButton.setFont(new Font("援대┝", Font.BOLD, 18));
		followButton.setBorderPainted(false);
		followButton.setContentAreaFilled(false);
		followButton.setFocusPainted(false);
		followButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (myId != id) {
					DBConnection DBcon = new DBConnection();
					DBcon.connect();
					String follow = String.format("insert into follower values('%s', '%s');" , myId, id);
					try{
						Statement followstmt = DBcon.connection.createStatement();
						followstmt.executeUpdate(follow);
						DBcon.connection.close();
						JOptionPane.showMessageDialog(container, "移쒓뎄異붽� �릺�뿀�뒿�땲�떎!");
					}catch(SQLException SQLE) {
						SQLE.printStackTrace();
					}
				}
				
			}
		});
		followButton.setBounds(212, 14, 53, 23);
		profilePanel.add(followButton);
		
		// 醫뗭븘�슂踰꾪듉 �넃�쓣 �옄由�
		JPanel etcPanel = new JPanel();
		etcPanel.setBounds(0, 252, 500, 43);
		postPanel.add(etcPanel);
		etcPanel.setLayout(null);
		
		likeNum = new JTextField();
		likeNum.setBounds(64, 11, 56, 21);
		etcPanel.add(likeNum);
		likeNum.setColumns(10);
		likeNum.setText(String.valueOf(postlike));
		
		// 醫뗭븘�슂 踰꾪듉�쓣 �늻瑜대㈃ �떎�떆媛꾩쑝濡� 利앷��릺寃�
		JButton likeButton = new JButton(msg);
		likeButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				DBConnection DBcon = new DBConnection();
				DBcon.connect();
				String query = String.format("update post set likeNum = likeNum + 1 where id ='%s' and post = '%s' and postTitle = '%s';", id, post, post_title);
				String likeNumquery = String.format("select likeNum from post where id = '%s' and post = '%s' and postTitle = '%s';", id, post, post_title);
				try {
					Statement stmt = DBcon.connection.createStatement();
					stmt.executeUpdate(query);
					ResultSet likeResult = stmt.executeQuery(likeNumquery);
					likeResult.next();
					likeNum.setText(likeResult.getString("likeNum"));
					DBcon.connection.close();
				}catch(SQLException SQLE) {
					SQLE.printStackTrace();
				}
			}
		});
		likeButton.setBounds(12, 10, 56, 23);
		etcPanel.add(likeButton);
	}
}
}

// db connection�븯�뒗 遺�遺�
// local�뿉�꽌 �븷�븣�뒗 �옄湲� db�뿉 留욊쾶 �빐以섏빞�옒
class DBConnection{
	Connection connection;
	
	public void connect() {
		String url = "jdbc:mysql://localhost:3306/twitter";
		String user = "twitter";
		String password = "gachon";
		
		try {
			connection = DriverManager.getConnection(url, user, password); 
		}catch(SQLException e) {
			e.printStackTrace();
		}
	}
}
