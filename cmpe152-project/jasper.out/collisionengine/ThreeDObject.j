.source                  ThreeDObject.java
.class                   abstract collisionengine/ThreeDObject
.super                   java/lang/Object

.field                   center Lcollisionengine/Point;
.field                   objvelocity Lcollisionengine/Velocity;
.field                   objectSpace [[[Ljava/lang/Boolean;
.field                   name Ljava/lang/String;

.method                  public <init>()V
   .limit stack          3
   .limit locals         1
   .line                 6
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 103
   aload_0               
   ldc                   "no name"
   putfield              collisionengine/ThreeDObject/name Ljava/lang/String;
   .line                 7
   aload_0               
   new                   collisionengine/Point
   dup                   
   invokespecial         collisionengine/Point/<init>()V
   invokevirtual         collisionengine/ThreeDObject/initCenter(Lcollisionengine/Point;)V
   .line                 8
   aload_0               
   new                   collisionengine/Velocity
   dup                   
   invokespecial         collisionengine/Velocity/<init>()V
   invokevirtual         collisionengine/ThreeDObject/initVelocity(Lcollisionengine/Velocity;)V
   .line                 9
   return                
.end method              

.method                  public <init>(Lcollisionengine/Point;)V
   .limit stack          3
   .limit locals         2
   .line                 11
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 103
   aload_0               
   ldc                   "no name"
   putfield              collisionengine/ThreeDObject/name Ljava/lang/String;
   .line                 12
   aload_0               
   aload_1               
   invokevirtual         collisionengine/ThreeDObject/initCenter(Lcollisionengine/Point;)V
   .line                 13
   aload_0               
   new                   collisionengine/Velocity
   dup                   
   invokespecial         collisionengine/Velocity/<init>()V
   invokevirtual         collisionengine/ThreeDObject/initVelocity(Lcollisionengine/Velocity;)V
   .line                 14
   return                
.end method              

.method                  public <init>(Lcollisionengine/Velocity;)V
   .limit stack          3
   .limit locals         2
   .line                 17
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 103
   aload_0               
   ldc                   "no name"
   putfield              collisionengine/ThreeDObject/name Ljava/lang/String;
   .line                 18
   aload_0               
   aload_1               
   invokevirtual         collisionengine/ThreeDObject/initVelocity(Lcollisionengine/Velocity;)V
   .line                 19
   aload_0               
   new                   collisionengine/Point
   dup                   
   invokespecial         collisionengine/Point/<init>()V
   invokevirtual         collisionengine/ThreeDObject/initCenter(Lcollisionengine/Point;)V
   .line                 20
   return                
.end method              

.method                  public <init>(Lcollisionengine/Point;Lcollisionengine/Velocity;)V
   .limit stack          2
   .limit locals         3
   .line                 22
   aload_0               
   invokespecial         java/lang/Object/<init>()V
   .line                 103
   aload_0               
   ldc                   "no name"
   putfield              collisionengine/ThreeDObject/name Ljava/lang/String;
   .line                 23
   aload_0               
   aload_2               
   invokevirtual         collisionengine/ThreeDObject/initVelocity(Lcollisionengine/Velocity;)V
   .line                 24
   aload_0               
   aload_1               
   invokevirtual         collisionengine/ThreeDObject/initCenter(Lcollisionengine/Point;)V
   .line                 25
   return                
.end method              

.method                  public initCenter(Lcollisionengine/Point;)V
   .limit stack          6
   .limit locals         2
   .line                 28
   aload_0               
   new                   collisionengine/Point
   dup                   
   aload_1               
   getfield              collisionengine/Point/x I
   aload_1               
   getfield              collisionengine/Point/y I
   aload_1               
   getfield              collisionengine/Point/z I
   invokespecial         collisionengine/Point/<init>(III)V
   putfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   .line                 29
   return                
.end method              

.method                  public initVelocity(Lcollisionengine/Velocity;)V
   .limit stack          6
   .limit locals         2
   .line                 32
   aload_0               
   new                   collisionengine/Velocity
   dup                   
   aload_1               
   getfield              collisionengine/Velocity/dx I
   aload_1               
   getfield              collisionengine/Velocity/dy I
   aload_1               
   getfield              collisionengine/Velocity/dz I
   invokespecial         collisionengine/Velocity/<init>(III)V
   putfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   .line                 33
   return                
.end method              

.method                  public putInEnvironment(Lcollisionengine/Point;)V
   .limit stack          2
   .limit locals         2
   .line                 36
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   aload_1               
   getfield              collisionengine/Point/x I
   putfield              collisionengine/Point/x I
   .line                 37
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   aload_1               
   getfield              collisionengine/Point/y I
   putfield              collisionengine/Point/y I
   .line                 38
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   aload_1               
   getfield              collisionengine/Point/z I
   putfield              collisionengine/Point/z I
   .line                 39
   return                
.end method              

.method                  public move(Lcollisionengine/Point;I)V
   .limit stack          3
   .limit locals         3
   .line                 43
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Point/x I
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/x I
   isub                  
   iload_2               
   idiv                  
   putfield              collisionengine/Velocity/dx I
   .line                 44
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Point/y I
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/y I
   isub                  
   iload_2               
   idiv                  
   putfield              collisionengine/Velocity/dy I
   .line                 45
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Point/z I
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/z I
   isub                  
   iload_2               
   idiv                  
   putfield              collisionengine/Velocity/dz I
   .line                 46
   return                
.end method              

.method                  public move(Lcollisionengine/Velocity;)V
   .limit stack          2
   .limit locals         2
   .line                 49
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Velocity/dx I
   putfield              collisionengine/Velocity/dx I
   .line                 50
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Velocity/dy I
   putfield              collisionengine/Velocity/dy I
   .line                 51
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   aload_1               
   getfield              collisionengine/Velocity/dz I
   putfield              collisionengine/Velocity/dz I
   .line                 52
   return                
.end method              

.method                  public timestep()V
   .limit stack          3
   .limit locals         1
   .line                 55
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   dup                   
   getfield              collisionengine/Point/x I
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dx I
   iadd                  
   putfield              collisionengine/Point/x I
   .line                 56
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   dup                   
   getfield              collisionengine/Point/y I
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dy I
   iadd                  
   putfield              collisionengine/Point/y I
   .line                 57
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   dup                   
   getfield              collisionengine/Point/z I
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dz I
   iadd                  
   putfield              collisionengine/Point/z I
   .line                 58
   return                
.end method              

.method                  public rotate(I)V
   .limit stack          0
   .limit locals         2
   .line                 62
   return                
.end method              

.method                  abstract buildSpace()V
.end method              

.method                  public setName(Ljava/lang/String;)V
   .limit stack          2
   .limit locals         2
   .line                 67
   aload_0               
   aload_1               
   putfield              collisionengine/ThreeDObject/name Ljava/lang/String;
   .line                 68
   return                
.end method              

.method                  public printLocation()V
   .limit stack          6
   .limit locals         1
   .line                 71
   getstatic             java/lang/System/out Ljava/io/PrintStream;
   ldc                   "x=%d, y=%d, z=%d"
   iconst_3              
   anewarray             java/lang/Object
   dup                   
   iconst_0              
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/x I
   invokestatic          java/lang/Integer/valueOf(I)Ljava/lang/Integer;
   aastore               
   dup                   
   iconst_1              
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/y I
   invokestatic          java/lang/Integer/valueOf(I)Ljava/lang/Integer;
   aastore               
   dup                   
   iconst_2              
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/z I
   invokestatic          java/lang/Integer/valueOf(I)Ljava/lang/Integer;
   aastore               
   invokevirtual         java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
   pop                   
   .line                 72
   return                
.end method              

.method                  public test1()Lcollisionengine/ThreeDObject;
   .limit stack          3
   .limit locals         2
   .line                 75
   new                   collisionengine/ThreeDObject$1
   dup                   
   aload_0               
   invokespecial         collisionengine/ThreeDObject$1/<init>(Lcollisionengine/ThreeDObject;)V
   astore_1              
   .line                 83
   aload_1               
   areturn               
.end method              

.method                  public getx()I
   .limit stack          1
   .limit locals         1
   .line                 85
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/x I
   ireturn               
.end method              

.method                  public gety()I
   .limit stack          1
   .limit locals         1
   .line                 86
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/y I
   ireturn               
.end method              

.method                  public getz()I
   .limit stack          1
   .limit locals         1
   .line                 87
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   getfield              collisionengine/Point/z I
   ireturn               
.end method              

.method                  public getdx()I
   .limit stack          1
   .limit locals         1
   .line                 88
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dx I
   ireturn               
.end method              

.method                  public getdy()I
   .limit stack          1
   .limit locals         1
   .line                 89
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dy I
   ireturn               
.end method              

.method                  public getdz()I
   .limit stack          1
   .limit locals         1
   .line                 90
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   getfield              collisionengine/Velocity/dz I
   ireturn               
.end method              

.method                  public setx(I)V
   .limit stack          2
   .limit locals         2
   .line                 92
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   iload_1               
   putfield              collisionengine/Point/x I
   return                
.end method              

.method                  public sety(I)V
   .limit stack          2
   .limit locals         2
   .line                 93
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   iload_1               
   putfield              collisionengine/Point/y I
   return                
.end method              

.method                  public setz(I)V
   .limit stack          2
   .limit locals         2
   .line                 94
   aload_0               
   getfield              collisionengine/ThreeDObject/center Lcollisionengine/Point;
   iload_1               
   putfield              collisionengine/Point/z I
   return                
.end method              

.method                  public setdx(I)V
   .limit stack          2
   .limit locals         2
   .line                 95
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   iload_1               
   putfield              collisionengine/Velocity/dx I
   return                
.end method              

.method                  public setdy(I)V
   .limit stack          2
   .limit locals         2
   .line                 96
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   iload_1               
   putfield              collisionengine/Velocity/dy I
   return                
.end method              

.method                  public setdz(I)V
   .limit stack          2
   .limit locals         2
   .line                 97
   aload_0               
   getfield              collisionengine/ThreeDObject/objvelocity Lcollisionengine/Velocity;
   iload_1               
   putfield              collisionengine/Velocity/dz I
   return                
.end method              

