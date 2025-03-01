.class public collisionengine/basictest
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static basicenvEngine Lcollisionengine/CollisionEngine;
.field private static xp I
.field private static cubeobj Lcollisionengine/RectPrism;

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
		default: END_COLLISION

	END_COLLISION:
	return

.limit locals 1
.limit stack 50
.end method


.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        collisionengine/basictest/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        collisionengine/basictest/_standardIn LPascalTextIn;

	new collisionengine/CollisionEngine
	dup
	ldc 100
	ldc 100
	ldc 100
	invokenonvirtual collisionengine/CollisionEngine/<init>(III)V
	putstatic	collisionengine/basictest/basicenvEngine Lcollisionengine/CollisionEngine;
	ldc	5
	putstatic	collisionengine/basictest/xp I

	new collisionengine/RectPrism
	dup
	ldc	3
	ldc	3
	ldc	3
	invokenonvirtual collisionengine/RectPrism/<init>(III)V
	dup
	putstatic collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;
	ldc "cubeobj"
	invokevirtual collisionengine/RectPrism/setName(Ljava/lang/String;)V

	getstatic	collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;

	invokevirtual collisionengine/RectPrism.getdx()I
	getstatic	collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;

	invokevirtual collisionengine/RectPrism.getdy()I
	iadd
	putstatic	collisionengine/basictest/xp I

; intxp=5

	ldc	5
	putstatic	collisionengine/basictest/xp I


; cubecubeobj=[height=3,width=3,length=3]

	new collisionengine/RectPrism
	dup
	ldc	3
	ldc	3
	ldc	3
	invokenonvirtual collisionengine/RectPrism/<init>(III)V
	dup
	putstatic collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;
	ldc "cubeobj"
	invokevirtual collisionengine/RectPrism/setName(Ljava/lang/String;)V


; xp=cubeobj.dx+cubeobj.dy

	getstatic	collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;

	invokevirtual collisionengine/RectPrism.getdx()I
	getstatic	collisionengine/basictest/cubeobj Lcollisionengine/RectPrism;

	invokevirtual collisionengine/RectPrism.getdy()I
	iadd
	putstatic	collisionengine/basictest/xp I
	ldc	5
	putstatic	collisionengine/basictest/xp I

; xp=5

	ldc	5
	putstatic	collisionengine/basictest/xp I
	getstatic collisionengine/basictest/basicenvEngine Lcollisionengine/CollisionEngine;
	invokevirtual collisionengine/CollisionEngine/printStatus()V

	getstatic     collisionengine/basictest/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
