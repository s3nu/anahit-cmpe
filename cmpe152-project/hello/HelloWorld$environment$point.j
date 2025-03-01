.source                  HelloWorld.java
.class                   hello/HelloWorld$environment$point
.super                   java/lang/Object

.field                   private x I
.field                   private y I
.field                   private z I

.method                  public <init>()V
   .limit stack          4
   .limit locals         1
   .line                 9
   aload_0               
   iconst_0              
   iconst_0              
   iconst_0              
   invokespecial         hello/HelloWorld$environment$point/<init>(III)V
   return                
.end method              

.method                  public <init>(III)V
   .limit stack          2
   .limit locals         4
   .line                 11
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 12
   aload_0               
   iload_1               
   putfield              hello/HelloWorld$environment$point/x I
   .line                 13
   aload_0               
   iload_2               
   putfield              hello/HelloWorld$environment$point/y I
   .line                 14
   aload_0               
   iload_3               
   putfield              hello/HelloWorld$environment$point/z I
   .line                 15
   return                
.end method              

.method                  static access$000(Lhello/HelloWorld$environment$point;)I
   .limit stack          1
   .limit locals         1
   .line                 6
   aload_0               
   getfield              hello/HelloWorld$environment$point/x I
   ireturn               
.end method              

