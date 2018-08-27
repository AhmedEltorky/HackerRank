import java.util.*;

class Student {
    
	private int id;
	private String fname;
	private double cgpa;
    
	public Student(int id, String fname, double cgpa) {
		super();
		this.id = id;
		this.fname = fname;
		this.cgpa = cgpa;
	}
    
	public int getId() {
		return id;
	}
    
	public String getFname() {
		return fname;
	}
    
	public double getCgpa() {
		return cgpa;
	}
}

//Complete the code
public class Solution {
    
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int testCases = Integer.parseInt(in.nextLine());
		
		List<Student> studentList = new ArrayList<Student>();
		while (testCases > 0){
			int id = in.nextInt();
			String fname = in.next();
			double cgpa = in.nextDouble();
			
			Student st = new Student(id, fname, cgpa);
			studentList.add(st);
			
			testCases--;
		}
        
        //first solution
        /*double max;
        int maxIndex;
        for (int i = 0;i < studentList.size();i++){
            max = studentList.get(i).getCgpa();
            maxIndex = i;
            for (int j = i+1;j < studentList.size();j++){
                if (studentList.get(j).getCgpa() > max){
                    max = studentList.get(j).getCgpa();
                    maxIndex = j;
                } else if (studentList.get(j).getCgpa() == max){
                    if (studentList.get(j).getFname().compareTo(studentList.get(maxIndex).getFname()) < 1){
                        maxIndex = j;                        
                    } else if (studentList.get(j).getFname().compareTo(studentList.get(maxIndex).getFname()) == 0){
                        if (studentList.get(j).getId() > studentList.get(maxIndex).getId()){
                            maxIndex = j;
                        }                        
                    }
                }
            }
            studentList.add(i, studentList.get(maxIndex));
            studentList.remove(maxIndex+1);            
        }*/
        
        
        // second solution
        Comparator<Student> stComp = (Student a, Student b) -> {            
                if (a.getCgpa() > b.getCgpa()){
                    return 1;
                } else if (a.getCgpa() < b.getCgpa()){
                    return 2;                    
                } else {
                    if (a.getFname().compareTo(b.getFname()) < 1){
                        return 1;                       
                    } else if (a.getFname().compareTo(b.getFname()) > 1){
                        return 2;
                    } else {
                        if (a.getId() > b.getId()){
                            return 1;
                        } else {
                            return 2;
                        }                       
                    }
                }
        };
        
        int maxIndx;
        for (int i = 0;i < studentList.size();i++){
            maxIndx = i;
            for (int j = i+1;j < studentList.size();j++){
                if (stComp.compare(studentList.get(maxIndx), studentList.get(j)) == 2){
                    maxIndx = j;                    
                }
            }
            studentList.add(i, studentList.get(maxIndx));
            studentList.remove(maxIndx+1);
        }
        
      
      	for(Student st: studentList){
			System.out.println(st.getFname());
		}
	}
}
