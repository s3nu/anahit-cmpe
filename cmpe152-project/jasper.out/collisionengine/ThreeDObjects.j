.source                  ThreeDObjects.java
.class                   public collisionengine/ThreeDObjects
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
   .limit stack          6
   .limit locals         3
   .line                 188
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "ThreeDObjects ... "
   invokevirtual         java/io/PrintStream/println(Ljava/lang/String;)V
   .line                 189
   new                   collisionengine/ThreeDObjects
   dup                   
   invokespecial         collisionengine/ThreeDObjects/<init>()V
   astore_1              
   .line                 190
   new                   collisionengine/ThreeDObjects$rectPrism
   dup                   
   aload_1               
   dup                   
   invokevirtual         java/lang/Object/getClass()Ljava/lang/Class;
   pop                   
   iconst_1              
   iconst_2              
   iconst_3              
   invokespecial         collisionengine/ThreeDObjects$rectPrism/<init>(Lcollisionengine/ThreeDObjects;III)V
   astore_2              
   .line                 191
   aload_2               
   new                   collisionengine/ThreeDObjects$point
   dup                   
   iconst_1              
   iconst_1              
   iconst_1              
   invokespecial         collisionengine/ThreeDObjects$point/<init>(III)V
   iconst_1              
   invokevirtual         collisionengine/ThreeDObjects$rectPrism/move(Lcollisionengine/ThreeDObjects$point;I)V
   .line                 192
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   aload_2               
   getfield              collisionengine/ThreeDObjects$rectPrism/objvelocity Lcollisionengine/ThreeDObjects$velocity;
   getfield              collisionengine/ThreeDObjects$velocity/dx I
   invokevirtual         java/io/PrintStream/println(I)V
   .line                 193
   return                
.end method              

