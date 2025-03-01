.class public collisionengine/testing
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static environmentObject [[[I
.field private static cubeobject [I
.field private static cubeobjectcenter [I
.field private static _testengine Lcollisionengine/CollisionEngine;
.field private static _testPoint Lcollisionengine/Point;
.field private static _testrectprism Lcollisionengine/RectPrism;


.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        collisionengine/testing/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        collisionengine/testing/_standardIn LPascalTextIn;

	new collisionengine/CollisionEngine
	dup
	ldc 1
	ldc 2
	ldc 3
	invokespecial collisionengine/CollisionEngine/<init>(III)V
	putstatic 		collisionengine/testing/_testengine Lcollisionengine/CollisionEngine;

	getstatic collisionengine/testing/_testengine Lcollisionengine/CollisionEngine;
	invokevirtual collisionengine/CollisionEngine/printStatus()V

    new collisionengine/Point
	dup
	invokenonvirtual collisionengine/Point/<init>()V
	putstatic collisionengine/testing/_testPoint Lcollisionengine/Point;

    new collisionengine/RectPrism
	dup
	iconst_1
	iconst_2
	iconst_3
    invokenonvirtual collisionengine/RectPrism/<init>(III)V
	putstatic collisionengine/testing/_testrectprism Lcollisionengine/RectPrism;


; cubecubeobject=[height=1,width=1,length=2]

	getstatic collisionengine/testing/_testengine Lcollisionengine/CollisionEngine;
	getstatic collisionengine/testing/_testrectprism Lcollisionengine/RectPrism;
	invokevirtual collisionengine/CollisionEngine/addObject(Lcollisionengine/ThreeDObject;)V

	getstatic     collisionengine/testing/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
