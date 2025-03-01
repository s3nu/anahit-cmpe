.source                  HelloWorld.java
.class                   public hello/HelloWorld
.super                   java/lang/Object


.method                  public <init>()V
   .limit stack          1
   .limit locals         1
   .line                 3
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   return                
.end method              

.method                  public static main([Ljava/lang/String;)V
   .limit stack          5
   .limit locals         2
   .line                 20
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "Hello World!"
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   .line                 21
   new                   hello/HelloWorld$environment$point
   dup                   
   iconst_1              
   iconst_2              
   iconst_3              
   invokespecial         hello/HelloWorld$environment$point/<init>(III)V
   astore_1              
   .line                 22
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload_1               
   invokestatic          hello/HelloWorld$environment$point/access$000(Lhello/HelloWorld$environment$point;)I
   invokevirtual         java/io/PrintStream/println(I)V
   .line                 23
   return                
.end method              

