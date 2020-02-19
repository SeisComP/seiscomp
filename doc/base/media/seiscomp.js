(function() {


// Add sidebar interaction
window.onload = function() {
	var sidebarToggle = document.getElementById('sidebar-toggle');
	if ( !sidebarToggle ) return;

	var top_nav_el = document.getElementsByClassName('nav');
	var anchors_container_el = document.getElementById('anchors-container');
	var anchors_top_el = document.getElementById('anchors-top');
	var anchors_bottom_el = document.getElementById('anchors-bottom');
	var anchors_el = document.getElementById('anchors');
	var sidebars = document.getElementsByClassName('sidebar');

	function toggleVisible(elem) {
		if ( elem.classList.contains('visible') )
			elem.classList.remove('visible');
		else
			elem.classList.add('visible');
	}

	function handleScrolling() {
		if ( anchors_top_el && anchors_bottom_el ) {
			var anchors_top_bounds = anchors_top_el.getBoundingClientRect();
			var anchors_bottom_bounds = anchors_bottom_el.getBoundingClientRect();
			var anchors_height = anchors_el.clientHeight;
			var nav_bounds = top_nav_el[0].getBoundingClientRect();

			if ( anchors_top_bounds.top < nav_bounds.bottom ) {
				var new_bottom = nav_bounds.bottom + anchors_height;
				if ( new_bottom < anchors_bottom_bounds.bottom && new_bottom < document.documentElement.clientHeight ) {
					anchors_el.classList.add('pinned');
					return;
				}
			}

			anchors_el.classList.remove('pinned');
		}
	}

	sidebarToggle.onclick = function() {
		var l = sidebars.length, i;
		for ( i = 0; i < l; ++i )
			toggleVisible(sidebars[i]);
	};

	function hasParent(node, parent) {
		while ( node !== parent ) {
			node = node.parentNode;
			if ( !node ) return false;
		}
		return true;
	}

	document.addEventListener("click", function(event) {
		var l = sidebars.length, i;
		for ( i = 0; i < l; ++i ) {
			if ( hasParent(event.target, sidebars[i]) )
				return;

			if ( hasParent(event.target, sidebarToggle) )
				return;
		}

		for ( i = 0; i < l; ++i )
			sidebars[i].classList.remove('visible');
	});

	var ticking = false;
	var lastY = 0;

	window.addEventListener('scroll', function() {
		var currentY = window.scrollY;

		if ( !ticking ) {
			window.requestAnimationFrame(function() {
				handleScrolling();
				ticking = false;
				lastY = currentY;
			});
		}

		ticking = true;
	});
};


})();
