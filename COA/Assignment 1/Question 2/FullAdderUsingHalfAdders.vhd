----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    14:57:36 09/22/2024 
-- Design Name: 
-- Module Name:    FullAdderUsingHalfAdders - Structural 
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

entity FullAdderUsingHalfAdders is
	Port ( A : in STD_LOGIC;
           B : in STD_LOGIC;
           Cin : in STD_LOGIC;
           Sum : out STD_LOGIC;
           Cout : out STD_LOGIC);
end FullAdderUsingHalfAdders;

architecture Structural of FullAdderUsingHalfAdders is
	signal S1, C1, C2 : STD_LOGIC;
    component HalfAdder is
        Port ( A : in STD_LOGIC;
               B : in STD_LOGIC;
               Sum : out STD_LOGIC;
               Carry : out STD_LOGIC);
    end component;

begin
	 HA1: HalfAdder port map (A, B, S1, C1);
    HA2: HalfAdder port map (S1, Cin, Sum, C2);
    Cout <= C1 OR C2;

end Structural;