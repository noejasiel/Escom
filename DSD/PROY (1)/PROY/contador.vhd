LIBRARY ieee ;
USE ieee.std_logic_1164.all ;
USE ieee.std_logic_unsigned.all ;

ENTITY upcount IS
PORT ( Clear, Clock : IN STD_LOGIC ;
Q : BUFFER STD_LOGIC_VECTOR(1 DOWNTO 0) ) ;
END upcount ;

ARCHITECTURE Behavior OF upcount IS
BEGIN
upcount: PROCESS (Clock)
BEGIN
	IF (Clock'EVENT AND Clock ='1')THEN
		IF Clear ='1' THEN
		Q <="00";
		ELSE
		Q <= Q +'1';
		END IF ;
	END IF;
END PROCESS;
END Behavior ;