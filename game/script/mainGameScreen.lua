--[[
   [
   [ Author: KK <thumbd03803@gmail.com>
   [
   [ mainGameScreen.lua
   [
   ]]

function testEnemy()
	local startX = 30
	local startY = 30
	local velX = 2
	local velY = 0

	co = coroutine.create(
	function()
		while (1) do
			startX = startX + velX
			startY = startY + velY
			coroutine.yield(startX, startY)
		end
	end
	)
	return co
end
