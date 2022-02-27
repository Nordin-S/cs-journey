package upg02.nosu2000.dt196g;

public class Course {
    private String courseName;
    private String courseId;
    private String coursePoints;
    private String courseDesc;

    /**
     * Creates a course instance, can have the attributes course id, course name, course points and course description.
     */
    public Course(){};

    /**
     * @param courseId
     * @param courseName
     * @param coursePoints
     */
    public Course(String courseId, String courseName, String coursePoints){
        this.courseId = courseId;
        this.courseName = courseName;
        this.coursePoints = coursePoints;
    }

    /**
     * @param courseId
     * @param courseName
     * @param coursePoints
     * @param courseDesc
     */
    public Course(String courseId, String courseName, String coursePoints, String courseDesc){
        this.courseId = courseId;
        this.courseName = courseName;
        this.coursePoints = coursePoints;
        this.courseDesc = courseDesc;
    }
    //setters
    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public void setCourseId(String courseId) {
        this.courseId = courseId;
    }

    public void setCoursePoints(String coursePoints) {
        this.coursePoints = coursePoints;
    }

    public void setCourseDesc(String courseDesc) {
        this.courseDesc = courseDesc;
    }
    //getters
    public String getCourseName() {
        return courseName;
    }

    public String getCourseId() {
        return courseId;
    }

    public String getCoursePoints() {
        return coursePoints;
    }

    public String getCourseDesc() {
        return courseDesc;
    }

    /**
     * Prints out the attributes of this object instance
     */
    public void print() {
        System.out.println("Namn: " + courseName);
        System.out.println("Kurskod: " + courseId);
        System.out.println("Kurspoäng: " + coursePoints + " HP");
        System.out.println("Beskrivning: " + courseDesc);
    }

    /**
     * @return
     * The members of this instance are returned as a string using an overridden toString()
     */
    @Override
    public String toString() {
        return "Course{" +
                "\n\tNamn='" + courseName + '\'' +
                ", \n\tKurskod='" + courseId + '\'' +
                ", \n\tKurspoäng='" + coursePoints + " HP\'" +
                ", \n\tBeskrivning='" + courseDesc + '\'' +
                '}';
    }
}
