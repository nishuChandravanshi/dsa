import java.util.*;

class Comp implements Comparator<Integer>{
    Map<Integer, Integer> mp;
    public int compare(Integer p1, Integer p2)
    {
        mp = PokerTest.toComp;
        if(mp.get(p1)>mp.get(p2)) return -1;
        else if(mp.get(p1)<mp.get(p2)) return 1;
        return p2-p1;
    }
}


public class PokerTest {
    public static final String PLAYER1_WINNER = "Hand 1 wins";
    public static final String PLAYER2_WINNER = "Hand 2 wins";
    public static final String DRAW = "Draw";
    
    Map<Character, Integer> map;
    static Map<Integer, Integer> toComp;

    List<Integer> arr1, arr2;


    public int compare(String player1, String player2) {
        map = new HashMap<Character, Integer>();
        fill();
        arr1=fillMap(player1);
        arr2=fillMap(player2);
        int v1=fun(player1,1);
        int v2 = fun(player2,2);
        if(v1!=v2)
            return v1-v2;
        return checkDraw(player1, player2);
    }

    public int checkDraw(String player1, String player2)
    {
        List<Integer> ar1 = new ArrayList<Integer>();
        List<Integer>ar2 = new ArrayList<Integer>();
        String []strs1 = player1.split(",");
        String []strs2 = player2.split(",");
        
        Map<Integer,Integer> m1 = new HashMap<Integer,Integer>();
        Map<Integer,Integer> m2 = new HashMap<Integer,Integer>();

        for(String str: strs1)
        {
            if(map.containsKey(str.charAt(1)))
            {
                ar1.add(map.get(str.charAt(1)));
                Integer temp;
                if(m1.containsKey(map.get(str.charAt(1))))
                {
                    temp = m1.get(map.get(str.charAt(1)));
                }
                else temp = 0;

                m1.put(map.get(str.charAt(1)), 1+temp);
            }
            
        }
        toComp = m1;

        Collections.sort(ar1, new Comp());
        for(String str: strs2)
        {
            Integer temp;
            if(map.containsKey(str.charAt(1)))
            {
                temp = map.get(str.charAt(1));
            }
            else temp =0;
            ar2.add(temp);
            Integer temp1 =0;
            if(m2.containsKey(temp))
            {
                temp1 =m2.get(temp);
            }
            else temp1 =0;
            m2.put(temp, 1+temp1);
        }
        toComp=m2;
        Collections.sort(ar2, new Comp());
        for(int i=0;i<ar1.size();i++)
        {
            if(ar1.get(i)>ar2.get(i)) return 1;
            if(ar1.get(i)<ar2.get(i)) return -1;
        }
        return 0;
    }

    public List<Integer> fillMap(String p1)
    {
        String []strs1 = p1.split(",");
        Map<Character, Integer> cmap1 = new HashMap<Character, Integer>();
        for(String str:strs1)
        {
            Integer temp;
            if(cmap1.containsKey(str.charAt(1)))
            {
                temp = cmap1.get(str.charAt(1));
            }
            else temp =0;
            cmap1.put(str.charAt(1), 1+temp);
        }
        List<Integer>arr = new ArrayList<Integer>();
        for(Character s:cmap1.keySet()){
            arr.add(cmap1.get(s));
        }
        Collections.sort(arr);
        return arr;
    }

    public void fill()
    {
        map.put('A',1);
        map.put('2',2);
        map.put('3',3);
        map.put('4',4);
        map.put('5',5);
        map.put('6',6);
        map.put('7',7);
        map.put('8',8);
        map.put('9',9);
        map.put('T',10);
        map.put('J',11);
        map.put('Q',12);
        map.put('K',13);
    }

    public int fun(String p1, int t)
    {
        if(cat1(p1,t)) return 8;
        if(cat2(p1,t)) return 7;
        if(cat3(p1,t)) return 6;
        if(cat4(p1,t)) return 5;
        if(cat5(p1,t)) return 4;
        if(cat6(p1,t)) return 3;
        if(cat7(p1,t)) return 2;
        if(cat8(p1,t)) return 1;
        if(cat9(p1,t)) return 0;
        return -1;
    }

    public boolean cat1(String s, int t)
    {
        return (cat4(s,t) && cat5(s,t));
    }
    
    public boolean cat2(String s, int t)
    {
        List<Integer> arr;
        if(t==1)
        {
            arr = arr1;
        }
        else {
            arr = arr2;
        }
        if(arr.size()!=2) return false;
        if(arr.get(0)==1 && arr.get(1)==4) return true;
        return false;
    }

    
    public boolean cat3(String s, int t)
    {
        List<Integer> arr;
        if(t==1)
        {
            arr = arr1;
        }
        else {
            arr = arr2;
        }
        if(arr.size()!=2) return false;
        if(arr.get(0)==2 && arr.get(1)==3) return true;
        return false;
    }
    
    public boolean cat4(String s, int t)
    {
        String[] strs = s.split(",");
        Set<Character> set = new HashSet<Character>();
        for(String str:strs)
        {
            set.add(str.charAt(0));
        }
        if(set.size()==1) return true;
        return false;
    }
    
    public boolean cat5(String s, int t)
    {
        String[] strs = s.split(",");
        int flag =0;
        List<Integer> list = new ArrayList<Integer>();
        for(String str:strs)
        {
            if(str.charAt(1)=='A'){
                flag++;
                continue;
            }
            list.add(map.get(str.charAt(1)));
        }
        if(flag>1) return false;
        Collections.sort(list);
        for(int i=0;i<list.size()-1;i++)
        {
            if(1+list.get(i)!=list.get(i+1))
                return false;
        }
        if(flag==0) return true;
        if(list.get(0)==2 || list.get(3)==13) return true;
        return false;
    }


    public boolean cat6(String s, int t)
    {
        List<Integer>arr;
        if(t==1)
        {
            arr=arr1;
        }
        else{
            arr =arr2;
        }
        if(arr.size()!=3)
            return false;
        if(arr.get(0)==1 && arr.get(1)==1 && arr.get(2)==3)
            return true;
        return false;
    }

    public boolean cat7(String s, int t)
    {
        List<Integer>arr;
        if(t==1)
        {
            arr=arr1;
        }
        else{
            arr =arr2;
        }
        if(arr.size()!=3)
            return false;
        if(arr.get(0)==1 && arr.get(1)==2 && arr.get(2)==2)
            return true;
        return false;
    }
    
    public boolean cat8(String s, int t)
    {
        List<Integer>arr;
        if(t==1)
        {
            arr=arr1;
        }
        else{
            arr =arr2;
        }
        if(arr.size()!=4)
            return false;
        if((arr.get(0)==1 && arr.get(1)==1 )|| (arr.get(0)==1 && arr.get(1)==2))
            return true;
        return false;
    }

    public boolean cat9(String s, int t)
    {
        return true;
    }
    

    public static void main(String[] args1) {
        Scanner s = new Scanner(System.in);
        while(s.hasNextLine()) {
            String line = s.nextLine();
            String[] args = line.split(" ");
            
            String type = args[0];
            if(type.equals("compare")) {
                // System.out.println(new PokerTest().compare(args[1], args[2]));
            
                int res = new PokerTest().compare(args[1], args[2]);
                if(res > 0)
                    System.out.println(PLAYER1_WINNER);
                if(res < 0)
                    System.out.println(PLAYER2_WINNER);
                if(res == 0)
                    System.out.println(DRAW);
            }
        }
        s.close();
    }
}