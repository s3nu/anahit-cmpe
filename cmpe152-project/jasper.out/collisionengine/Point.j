.source                  Point.java
.class                   public collisionengine/Point
.super                   java/lang/Object

.field                   public x I
.field                   public y I
.field                   public z I

.method                  public <init>()V
   .limit stack          4
   .limit locals         1
   .line                 6
   aload_0               
   iconst_0              
   iconst_0              
   iconst_0              
   invokespecial         collisionengine/Point/<init>(III)V
   return                
.end method              

.method                  public <init>([I)V
   .limit stack          5
   .limit locals         2
   .line                 7
   aload_0               
   aload_1               
   iconst_0              
   iaload                
   aload_1               
   iconst_1              
   iaload                
   aload_1               
   iconst_2              
   iaload                
   invokespecial         collisionengine/Point/<init>(III)V
   return                
.end method              

.method                  public <init>(III)V
   .limit stack          2
   .limit locals         4
   .line                 9
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 10
   aload_0               
   iload_1               
   putfield              collisionengine/Point/x I
   .line                 11
   aload_0               
   iload_2               
   putfield              collisionengine/Point/y I
   .line                 12
   aload_0               
   iload_3               
   putfield              collisionengine/Point/z I
   .line                 13
   return                
.end method              

.method                  public add(III)V
   .limit stack          3
   .limit locals         4
   .line                 16
   aload_0               
   dup                   
   getfield              collisionengine/Point/x I
   iload_1               
   iadd                  
   putfield              collisionengine/Point/x I
   .line                 17
   aload_0               
   dup                   
   getfield              collisionengine/Point/y I
   iload_2               
   iadd                  
   putfield              collisionengine/Point/y I
   .line                 18
   aload_0               
   dup                   
   getfield              collisionengine/Point/z I
   iload_3               
   iadd                  
   putfield              collisionengine/Point/z I
   .line                 19
   return                
.end method              

.method                  public static main([Ljava/lang/String;)V
   .limit stack          5
   .limit locals         2
   .line                 22
   new                   collisionengine/RectPrism
   dup                   
   iconst_1              
   iconst_1              
   iconst_1              
   invokespecial         collisionengine/RectPrism/<init>(III)V
   astore_1              
   .line                 23
   return                
.end method              

