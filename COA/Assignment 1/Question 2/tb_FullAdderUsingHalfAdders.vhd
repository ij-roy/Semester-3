--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:04:19 09/22/2024
-- Design Name:   
-- Module Name:   /home/ise/Assignment1/tb_FullAdderUsingHalfAdders.vhd
-- Project Name:  Assignment1
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: FullAdderUsingHalfAdders
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
 
ENTITY tb_FullAdderUsingHalfAdders IS
END tb_FullAdderUsingHalfAdders;
 
ARCHITECTURE behavior OF tb_FullAdderUsingHalfAdders IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT FullAdderUsingHalfAdders
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         Cin : IN  std_logic;
         Sum : OUT  std_logic;
         Cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal Cin : std_logic := '0';

 	--Outputs
   signal Sum : std_logic;
   signal Cout : std_logic;
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: FullAdderUsingHalfAdders PORT MAP (
          A => A,
          B => B,
          Cin => Cin,
          Sum => Sum,
          Cout => Cout
        );
   -- Stimulus process
   stim_proc: process
   begin		
		A <= '0'; B <= '0'; Cin <= '0';
		wait for 10 ns;
		
		A <= '0'; B <= '0'; Cin <= '1';
		wait for 10 ns;

		A <= '0'; B <= '1'; Cin <= '0';
		wait for 10 ns;

		A <= '0'; B <= '1'; Cin <= '1';
		wait for 10 ns;

		A <= '1'; B <= '0'; Cin <= '0';
		wait for 10 ns;

		A <= '1'; B <= '0'; Cin <= '1';
		wait for 10 ns;

		A <= '1'; B <= '1'; Cin <= '0';
		wait for 10 ns;

		A <= '1'; B <= '1'; Cin <= '1';
		wait for 10 ns;
		
      wait;
   end process;

END;