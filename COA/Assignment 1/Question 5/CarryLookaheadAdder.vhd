----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:27:06 09/22/2024 
-- Design Name: 
-- Module Name:    CarryLookaheadAdder - Structural 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity CarryLookaheadAdder is
	 Port ( A : in STD_LOGIC_VECTOR(3 downto 0);
           B : in STD_LOGIC_VECTOR(3 downto 0);
           Cin : in STD_LOGIC;
           Sum : out STD_LOGIC_VECTOR(3 downto 0);
           Cout : out STD_LOGIC);
end CarryLookaheadAdder;

architecture Structural of CarryLookaheadAdder is
    signal P, G, C : STD_LOGIC_VECTOR(3 downto 0);
    component FullAdder is
        Port ( A : in STD_LOGIC;
               B : in STD_LOGIC;
               Cin : in STD_LOGIC;
               Sum : out STD_LOGIC;
               Cout : out STD_LOGIC);
    end component;
	 
begin
    P <= A XOR B;
    G <= A AND B;

    C(0) <= G(0) OR (P(0) AND Cin);
    C(1) <= G(1) OR (P(1) AND G(0)) OR (P(1) AND P(0) AND Cin);
    C(2) <= G(2) OR (P(2) AND G(1)) OR (P(2) AND P(1) AND G(0)) OR (P(2) AND P(1) AND P(0) AND Cin);
    C(3) <= G(3) OR (P(3) AND G(2)) OR (P(3) AND P(2) AND G(1)) OR (P(3) AND P(2) AND P(1) AND G(0)) OR (P(3) AND P(2) AND P(1) AND P(0) AND Cin);

    FA0: FullAdder port map (A(0), B(0), Cin,  Sum(0), C(0));
    FA1: FullAdder port map (A(1), B(1), C(0), Sum(1), C(1));
    FA2: FullAdder port map (A(2), B(2), C(1), Sum(2), C(2));
    FA3: FullAdder port map (A(3), B(3), C(2), Sum(3), C(3));

	Cout <= C(3);

end Structural;