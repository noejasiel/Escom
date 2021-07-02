LIBRARY ieee ;
USE ieee.std_logic_1164.all ;

ENTITY regn IS
GENERIC ( N : INTEGER := 8);
PORT ( R : IN STD_LOGIC_VECTOR(N-1 DOWNTO 0) ;
	Rin, Clock : IN STD_LOGIC ;
	Q : OUT STD_LOGIC_VECTOR(N-1 DOWNTO 0) ) ;
END regn ;

ARCHITECTURE Behavior OF regn IS
BEGIN
	PROCESS
	BEGIN
		WAIT UNTIL Clock'EVENT AND Clock ='1';
		IF Rin ='1'THEN
			Q <= R ;
		END IF ;
	END PROCESS ;
END Behavior ;

