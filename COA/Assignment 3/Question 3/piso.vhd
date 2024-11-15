----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:25:52 10/15/2024 
-- Design Name: 
-- Module Name:    piso - Behavioral 
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

entity piso is
	port(
	clk:in std_logic;
	reset: in std_logic;
	enable:in std_logic;
	mode : in std_logic;
	parallel_in : in std_logic_vector(3 downto 0);
	serial_in : in std_logic;
	serial_out: out std_logic);
end piso;

architecture Behavioral of piso is
	component d_ff is
		port ( d      : in std_logic;
		clk    : in std_logic;
		enable : in std_logic;
		reset  : in std_logic;
		q      : out std_logic);
	end component;
	signal d : STD_LOGIC_VECTOR(3 downto 0);
	signal t : STD_LOGIC_VECTOR(3 downto 0);
begin
step1:d_ff port map(d(0),clk,enable,reset,t(0));
step2:d_ff port map(d(1),clk,enable,reset,t(1));
step3:d_ff port map(d(2),clk,enable,reset,t(2));
step4:d_ff port map(d(3),clk,enable,reset,t(3));
process(clk,reset)
	begin
	if reset='1' then
		d<=(others=>'0');
		elsif rising_edge(clk) then
		if enable = '1' then
			if mode = '0' then
			d<=parallel_in;
			else
			d(3 downto 1)<=t(2 downto 0); 
			d(0)<=serial_in;
			end if;
		end if;
	end if;
end process;
serial_out<=t(3);

end Behavioral;