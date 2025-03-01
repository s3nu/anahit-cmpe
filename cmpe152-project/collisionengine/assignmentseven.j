.class public collisionengine/assignmentseven
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static j I
.field private static environmentObjectEngine Lcollisionengine/CollisionEngine;
.field private static timetomovecube I
.field private static pointObjectOne Lcollisionengine/Point;
.field private static pointObjectTwo Lcollisionengine/Point;
.field private static pointObjectThree Lcollisionengine/Point;
.field private static cubeobject Lcollisionengine/RectPrism;
.field private static sphereobject Lcollisionengine/Sphere;
.field private static cubeobjectTwo Lcollisionengine/RectPrism;

.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method


.method private static handleCollision(I)V

	iload_0
	lookupswitch
		1: L1
		2: L2
		3: L3
		default: END_COLLISION

	L1:
		invokestatic collisionengine/assignmentseven/collisionOne()V
		goto END_COLLISION
	L2:
		invokestatic collisionengine/assignmentseven/collisionTwo()V
		goto END_COLLISION
	L3:
		invokestatic collisionengine/assignmentseven/collisionThree()V
		goto END_COLLISION
	END_COLLISION:
	return

.limit locals 1
.limit stack 50
.end method



.method private static functionTwo(I)I

	iload 0
	putstatic collisionengine/assignmentseven/j I
	ldc	2
	getstatic	collisionengine/assignmentseven/j I
	imul
	ireturn

.limit locals 7
.limit stack 50
.end method



.method private static collisionOne()V


; print("colone")

	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc "col one "
	invokevirtual java/io/PrintStream.println(Ljava/lang/String;)V

; cubeobject.dy=20

	getstatic	collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;

	ldc	20
	invokevirtual collisionengine/RectPrism.setdy(I)V

; sphereobject.dx=5

	getstatic	collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;

	ldc	5
	invokevirtual collisionengine/Sphere.setdx(I)V
	return

.limit locals 6
.limit stack 50
.end method



.method private static collisionTwo()V


; print("coltwo")

	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc "col two "
	invokevirtual java/io/PrintStream.println(Ljava/lang/String;)V

; cubeobject.dx=10

	getstatic	collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;

	ldc	10
	invokevirtual collisionengine/RectPrism.setdx(I)V

; cubeobjectTwo.dz=2

	getstatic	collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;

	ldc	2
	invokevirtual collisionengine/RectPrism.setdz(I)V
	return

.limit locals 6
.limit stack 50
.end method



.method private static collisionThree()V


; print("colthree")

	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc "col three "
	invokevirtual java/io/PrintStream.println(Ljava/lang/String;)V

; sphereobject.dx=8

	getstatic	collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;

	ldc	8
	invokevirtual collisionengine/Sphere.setdx(I)V

; cubeobjectTwo.dz=3

	getstatic	collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;

	ldc	3
	invokevirtual collisionengine/RectPrism.setdz(I)V
	return

.limit locals 6
.limit stack 50
.end method


.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        collisionengine/assignmentseven/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        collisionengine/assignmentseven/_standardIn LPascalTextIn;

	new collisionengine/CollisionEngine
	dup
	ldc 100
	ldc 100
	ldc 100
	invokenonvirtual collisionengine/CollisionEngine/<init>(III)V
	putstatic	collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;

; inttimetomovecube=functionTwo(5)

	ldc	5
	invokestatic collisionengine/assignmentseven/functionTwo(I)I
	putstatic	collisionengine/assignmentseven/timetomovecube I


; pointpointObjectOne=[x=0,y=0,z=0]

	new collisionengine/Point
	dup
	ldc	0
	ldc	0
	ldc	0
	invokenonvirtual collisionengine/Point/<init>(III)V
	putstatic collisionengine/assignmentseven/pointObjectOne Lcollisionengine/Point;


; pointpointObjectTwo=[x=10,y=0,z=0]

	new collisionengine/Point
	dup
	ldc	10
	ldc	0
	ldc	0
	invokenonvirtual collisionengine/Point/<init>(III)V
	putstatic collisionengine/assignmentseven/pointObjectTwo Lcollisionengine/Point;


; pointpointObjectThree=[x=10,y=0,z=25]

	new collisionengine/Point
	dup
	ldc	10
	ldc	0
	ldc	25
	invokenonvirtual collisionengine/Point/<init>(III)V
	putstatic collisionengine/assignmentseven/pointObjectThree Lcollisionengine/Point;


; cubecubeobject=[height=1,width=1,length=2]

	new collisionengine/RectPrism
	dup
	ldc	1
	ldc	1
	ldc	2
	invokenonvirtual collisionengine/RectPrism/<init>(III)V
	dup
	putstatic collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;
	ldc "cubeobject"
	invokevirtual collisionengine/RectPrism.setName(Ljava/lang/String;)V


; spheresphereobject=[radius=2]

	new collisionengine/Sphere
	dup
	ldc	2
	invokenonvirtual collisionengine/Sphere/<init>(I)V
	dup
	putstatic collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;
	ldc "sphereobject"
	invokevirtual collisionengine/Sphere.setName(Ljava/lang/String;)V


; cubecubeobjectTwo=[height=3,width=3,length=4]

	new collisionengine/RectPrism
	dup
	ldc	3
	ldc	3
	ldc	4
	invokenonvirtual collisionengine/RectPrism/<init>(III)V
	dup
	putstatic collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;
	ldc "cubeobjectTwo"
	invokevirtual collisionengine/RectPrism.setName(Ljava/lang/String;)V


; putnenvcubeobjectpointObjectOne

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;
	getstatic collisionengine/assignmentseven/pointObjectOne Lcollisionengine/Point;
	invokevirtual collisionengine/CollisionEngine/addObject(Lcollisionengine/ThreeDObject;Lcollisionengine/Point;)V

; putnenvsphereobjectpointObjectTwo

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;
	getstatic collisionengine/assignmentseven/pointObjectTwo Lcollisionengine/Point;
	invokevirtual collisionengine/CollisionEngine/addObject(Lcollisionengine/ThreeDObject;Lcollisionengine/Point;)V

; putnenvcubeobjectTwopointObjectThree

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;
	getstatic collisionengine/assignmentseven/pointObjectThree Lcollisionengine/Point;
	invokevirtual collisionengine/CollisionEngine/addObject(Lcollisionengine/ThreeDObject;Lcollisionengine/Point;)V

; WHEN(cubeobject,sphereobject)THENcollisionOne

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic	collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;
	getstatic	collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;
	invokevirtual collisionengine/CollisionEngine.addCollision(Lcollisionengine/ThreeDObject;Lcollisionengine/ThreeDObject;)V

; WHEN(cubeobject,cubeobjectTwo)THENcollisionTwo

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic	collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;
	getstatic	collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;
	invokevirtual collisionengine/CollisionEngine.addCollision(Lcollisionengine/ThreeDObject;Lcollisionengine/ThreeDObject;)V

; WHEN(sphereobject,cubeobjectTwo)THENcollisionThree

	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	getstatic	collisionengine/assignmentseven/sphereobject Lcollisionengine/Sphere;
	getstatic	collisionengine/assignmentseven/cubeobjectTwo Lcollisionengine/RectPrism;
	invokevirtual collisionengine/CollisionEngine.addCollision(Lcollisionengine/ThreeDObject;Lcollisionengine/ThreeDObject;)V

; movecubeobjecttopointObjectTwointimetomovecube

	getstatic collisionengine/assignmentseven/cubeobject Lcollisionengine/RectPrism;
	getstatic collisionengine/assignmentseven/pointObjectTwo Lcollisionengine/Point;
	getstatic	collisionengine/assignmentseven/timetomovecube I
	invokevirtual collisionengine/ThreeDObject.move(Lcollisionengine/Point;I)V

; wait3

	ldc 0
	istore_3
	ldc	3
	istore_2
WAIT_STMT1LOOP1:
	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	invokevirtual collisionengine/CollisionEngine.timestep()[I
	ldc 1
	istore 4
	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	invokevirtual collisionengine/CollisionEngine.getNumCollisionHandles()I
	istore 5
WAIT_STMT1LOOP2:
	dup
	iload 4
	iaload
	ifne WAIT_STMT1_NO_HANDLE
	iload 4
	invokestatic collisionengine/assignmentseven/handleCollision(I)V
WAIT_STMT1_NO_HANDLE:
	iinc 4 1
	iload 4
	iload 5
	if_icmpne WAIT_STMT1LOOP2
	pop
	iinc 3 1
	iload 3
	iload_2
	if_icmpne WAIT_STMT1LOOP1
	getstatic collisionengine/assignmentseven/environmentObjectEngine Lcollisionengine/CollisionEngine;
	invokevirtual collisionengine/CollisionEngine/printStatus()V

	getstatic     collisionengine/assignmentseven/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
