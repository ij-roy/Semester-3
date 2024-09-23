--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:44:17 09/22/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment1/tb_CarryLookaheadAdder.vhd
-- Project Name:  Assignment1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CarryLookaheadAdder
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_CarryLookaheadAdder IS
END tb_CarryLookaheadAdder;
 
ARCHITECTURE behavior OF tb_CarryLookaheadAdder IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CarryLookaheadAdder
    PORT(
         A : IN  std_logic_vector(3 downto 0);
         B : IN  std_logic_vector(3 downto 0);
         Cin : IN  std_logic;
         Sum : OUT  std_logic_vector(3 downto 0);
         Cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic_vector(3 downto 0) := (others => '0');
   signal B : std_logic_vector(3 downto 0) := (others => '0');
   signal Cin : std_logic := '0';

 	--Outputs
   signal Sum : std_logic_vector(3 downto 0);
   signal Cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CarryLookaheadAdder PORT MAP (
          A => A,
          B => B,
          Cin => Cin,
          Sum => Sum,
          Cout => Cout
        );

   -- Stimulus process
   stim_proc: process
   begin		
	
		  A <= "0001"; B <= "0010"; Cin <= '0';
        wait for 10 ns;  

        A <= "0101"; B <= "0011"; Cin <= '1';
        wait for 10 ns;
		  
        A <= "1111"; B <= "1111"; Cin <= '1';
        wait for 10 ns; 

        A <= "0000"; B <= "0000"; Cin <= '0';
        wait for 10 ns; 
		  
        A <= "0110"; B <= "1001"; Cin <= '0';
        wait for 10 ns; 

        A <= "1000"; B <= "1000"; Cin <= '1';
        wait for 10 ns; 
		  
        A <= "1101"; B <= "0101"; Cin <= '0';
        wait for 10 ns; 
		  
        A <= "0011"; B <= "0111"; Cin <= '1';
        wait for 10 ns; 

        A <= "1110"; B <= "0001"; Cin <= '0';
        wait for 10 ns; 
		  
        A <= "0001"; B <= "0001"; Cin <= '1';
        wait for 10 ns; 
		  
      wait;
   end process;

END;